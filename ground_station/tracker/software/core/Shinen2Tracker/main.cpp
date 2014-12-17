/***************************************************
Cammand Line Auguments:
 
arg[1]: latitude  [deg]
arg[2]: longitude [deg]
arg[3]: altitude  [m]
arg[4]: unixtime  [sec]

OR

arg[1]: latitude       [deg]
arg[2]: longitude      [deg]
arg[3]: altitude       [m]
arg[4]: unixtime_start [sec]
arg[5]: unixtime_end   [sec]

****************************************************/
#include "shinen.h"
#include "pass.h"
#include "tf.h"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cmath>
using namespace std;

#define	DEG_TO_RAD(deg)	deg*M_PI/180.0
#define RAD_TO_DEG(rad)	rad*180.0/M_PI

int argIsValid (int argc, char* argv[])
{
	switch (argc) {
		
	case 5:
		cout << endl;
		cout << "----- Command Line Auguments -----" << endl;
		cout << "latitude: "  << argv[1] << endl;
		cout << "longitude: " << argv[2] << endl;
		cout << "altitude: "  << argv[3] << endl;
		cout << "unixtime: "  << argv[4] << endl;
		return 1;
		
	case 6:
		cout << endl;
		cout << "----- Command Line Auguments -----" << endl;
		cout << "latitude: "       << argv[1] << endl;
		cout << "longitude: "      << argv[2] << endl;
		cout << "altitude: "       << argv[3] << endl;
		cout << "unixtime_start: " << argv[4] << endl;
		cout << "unixtime_end: "   << argv[5] << endl;
		return 1;
		
	default: 
		cout << "[Error] Please input auguments correctly" << endl;
	
		cout << "-----" << endl;
		cout << "arg[1]: latitude  [deg]" << endl;
		cout << "arg[2]: longitude [deg]" << endl;
		cout << "arg[3]: altitude  [m]"   << endl;
		cout << "arg[4]: unixtime  [sec]" << endl;
		
		cout << "---or---" << endl;
		cout << "arg[1]: latitude       [deg]" << endl;
		cout << "arg[2]: longitude      [deg]" << endl;
		cout << "arg[3]: altitude       [m]"   << endl;
		cout << "arg[4]: unixtime_start [sec]" << endl;
		cout << "arg[5]: unixtime_end   [sec]" << endl;
		break;
	}
		
	return 0;
}

int main (int argc, char* argv[])
{
	// check the command line auguments
	if (!argIsValid (argc, argv)) {
		return 1;
	}
	
	Shinen2Tracker tracker;	// based on :public SpacecraftTracker, :public SpacecraftCalculator
	
	// [1] init the departure time (necessary to get DESPATCH phase)
	const double DepartureMjd = 56994.261129;   //2014/12/3
	tracker.setDepartureTime (DepartureMjd);
	// ---end of [1]
	
	// [2] init spacecraft orbit and parameters, observer geo-coord
	Shinen2Tracker:: SCDRec scd;// SpaceCraft Description
	scd.orbitInfo.epochMjd = DepartureMjd;
	scd.orbitInfo.positionEci[0] =  9230208.0;
	scd.orbitInfo.positionEci[1] =  -645302.0;
	scd.orbitInfo.positionEci[2] =     -161.0;
	scd.orbitInfo.velocityEci[0] =  6392.116;
	scd.orbitInfo.velocityEci[1] =  6952.874;
	scd.orbitInfo.velocityEci[2] = -4240.850;
	scd.param.ballisticCoeff = 150.0;
	tracker.setSpacecraftInfo (scd);
	tracker.setObserverGeoCoord (DEG_TO_RAD(atof (argv[1])), DEG_TO_RAD(atof (argv[2])), atof (argv[3]));
    
    { // added by HORIGUCHI J.
        Shinen2Tracker::SerializedSCDRec txt;
        tracker.getSpacecraftInfo(&txt);
        ofstream ofs("sin'en2.scd");
        ofs << "SIN'EN2" << endl;
        ofs << "SCD00002" << txt.info << endl;
        ofs << txt.param << endl;
    }
	// ---end of [2]
	
	double unixtime;
	double elevation, azimuth, doppler_down, doppler_up, distance;
	double latitude, longitude, altitude;
	double declination, rightascension;
	
	double unixtime_s = atof (argv[4]);
	double unixtime_e;
	argc >5 ? unixtime_e = atof (argv[5]) : unixtime_e = unixtime_s;
	
	// [3] set time at first, then get values
	const double outputDt = 3600.0;
	double t = unixtime_s;
    
	cout << endl;
	cout << "----- Results -----" << endl;
	cout << "unixtime, elevation[deg], azimuth[deg], uplink coeff, downlink coeff, distance[m], latitude[deg], longitude[deg], altitude[m], declination[deg], right ascension[deg]" << endl;
	
	while (1) {
		if (t > unixtime_e) {
			cout << "finished" << endl;
			break;
		}
		
		if (tracker.setTargetTime (t) != 0) {
			cout << "Range error, exit." << endl;
			break;
		}
		
		tracker.getTargetTime (&unixtime);
		tracker.getSpacecraftDirection (&elevation, &azimuth);
		tracker.getDopplerRatio (&doppler_down, &doppler_up);
		tracker.getDistanceEarthCentered (&distance);
		tracker.getSpacecraftGeoCoord (&latitude, &longitude, &altitude);
		tracker.getGeometryEarthCentered (&declination, &rightascension);
	    
		cout << setprecision (10);
		cout << unixtime << ",";
		cout << RAD_TO_DEG(elevation) << "," << RAD_TO_DEG(azimuth) << ",";
		cout << doppler_up << "," << doppler_down << ",";
		cout << distance << ",";
		cout << RAD_TO_DEG(latitude) << "," << RAD_TO_DEG(longitude) << ",";
		cout << altitude << ",";
		cout << RAD_TO_DEG(declination) << "," << RAD_TO_DEG(rightascension);
		cout << endl;
        
		t += outputDt;
	}
	
	// revert spacecraft position and velocity to the ones of the epoch (for next iteration)
	tracker.resetSpacecraftState ();
	
	// ---end of [3]

	// [4] find next pass

	PassFinder finder;
    
    double departureUnixtime;
    tf:: convertMjdToUnixtime (&departureUnixtime, DepartureMjd);
    finder.setDepartureTime (departureUnixtime);
    
	vector<Pass> passes = finder.findAll(&tracker, unixtime_s, unixtime_e, 60);

	cout << endl;
	cout << "----- Results -----" << endl;
	cout << "AOS, LOS, TCA" << endl;
	for (vector<Pass>::iterator it = passes.begin(); it != passes.end(); ++it) {
		cout << it->AOS << "," << it->LOS << "," << it->TCA << endl;
	}
	cout << endl;

	// ---end of [4]
    
	return 0;
}
