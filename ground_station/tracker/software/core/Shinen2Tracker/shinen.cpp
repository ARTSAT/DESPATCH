/********************************************************************************
* File Name : shinen.cpp
* Title     : 
* Programmer: Motki Kimura
* Belonging : 
* Date      : 2014.11.25
* Language  : C++
*********************************************************************************
* class to calculate the phase of Shin'en-2
*
********************************************************************************/
#include "shinen.h"

const double Shinen2Tracker:: SecondsRadioStop_ = (30.0 * 24.0) * 3600.0;

Shinen2Tracker:: Shinen2Tracker (void) : SpacecraftTracker (), departureMjd_ (0.0)
{
	
}

Shinen2Tracker:: Shinen2Tracker (double departureMjd, SCDRec const& scd) : SpacecraftTracker (scd), departureMjd_ (departureMjd)
{
	
}

Shinen2Tracker:: ~Shinen2Tracker (void)
{
	
}

void Shinen2Tracker:: setDepartureTime (double departureMjd)
{
	departureMjd_ = departureMjd;
}

void Shinen2Tracker:: getDepartureTime (double* departureMjd) const
{
	*departureMjd = departureMjd_;
}

int Shinen2Tracker:: setTargetTime (double unixtime) 
{
	double departureUnixtime;
	tf:: convertMjdToUnixtime (&departureUnixtime, departureMjd_);
	
	if (unixtime < departureUnixtime) {
		cout << setprecision (10);
		cout << "[ERROR] Specified unixtime (" << unixtime << ") is too small" << endl;
		cout << "[ERROR] Unixtime must be bigger than one at departure: " << departureUnixtime << endl;
		return -1;
		
	}
	else if (unixtime > departureUnixtime + SecondsRadioStop_) {
		cout << setprecision (10);
		cout << "[ERROR] Specified unixtime (" << unixtime << ") is too big" << endl;
		cout << "[ERROR] Unixtime must be smaller than one at transmitter-off: " << departureUnixtime + SecondsRadioStop_ << endl;
		return 1;
	}
	else;
	
	return SpacecraftTracker:: setTargetTime (unixtime);
}

void Shinen2Tracker:: test (double unixtime_s, double unixtime_e, double outputDt)
{
	if (unixtime_s > unixtime_e) {
		cout << "[ERROR] unixtime_e must be bigger than unixtime_s" << endl;
		return;
	}
	
	if (outputDt <= 0.0) {
		cout << "[ERROR] outputDt must bigger than zero." << endl;
		return;
	}
	
	// set departure time
	const double DepartureMjd = 56991.263027;
	setDepartureTime (DepartureMjd);
	
	// set spacecraft orbit information and parameter
	SCDRec scd;
	scd.orbitInfo.epochMjd = DepartureMjd;
	scd.orbitInfo.positionEci[0] =  9197375.0;
	scd.orbitInfo.positionEci[1] = -1010670.0;
	scd.orbitInfo.positionEci[2] =     -161.0;
	scd.orbitInfo.velocityEci[0] =  6662.697;
	scd.orbitInfo.velocityEci[1] =  6694.033;
	scd.orbitInfo.velocityEci[2] = -4240.850;
	scd.param.ballisticCoeff = 150.0;
	setSpacecraftInfo (scd);
	
	// variables
	double distance;
	
	double utime = unixtime_s;
	
	cout << "unixtime, distance" << endl;
	do {
		setTargetTime (utime);
		
		getDistanceEarthCentered (&distance);
		
		cout << setprecision (10);
		cout << utime << ",";
		cout << distance;
		cout << endl;
		
		utime += outputDt;
		
	} while (utime < unixtime_e);
}

void Shinen2Tracker:: calcSecondsFromDeparture (double* secondsFromDeparture) const
{
	double epochMjd;
	getEpochTime (&epochMjd);
	double epochUnixtime;
	tf:: convertMjdToUnixtime (&epochUnixtime, epochMjd);
	
	double departureUnixtime;
	tf:: convertMjdToUnixtime (&departureUnixtime, departureMjd_);
	
	double secondsFromEpoch;
	getSecondsFromEpoch (&secondsFromEpoch);
	
	*secondsFromDeparture = (epochUnixtime - departureUnixtime) + secondsFromEpoch;
}