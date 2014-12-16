#include "c.h"
#include "despatch.h"
#include "pass.h"

#define DEG_TO_RAD(deg) deg*M_PI/180.0
#define RAD_TO_DEG(rad)rad*180.0/M_PI

const double DepartureMjd = 56991.265891;

Tracker TrackerNew(void)
{
  DespatchTracker* tracker = new DespatchTracker;

  // [1] init the departure time (necessary to get DESPATCH mode)
  tracker->setDepartureTime (DepartureMjd);
  // ---end of [1]

  // [2] init spacecraft orbit and parameters, observer geo-coord
  DespatchTracker:: SCDRec scd;// SpaceCraft Description
  scd.orbitInfo.epochMjd = DepartureMjd;
  scd.orbitInfo.positionEci[0] = 10724614.0;
  scd.orbitInfo.positionEci[1] =   660629.0;
  scd.orbitInfo.positionEci[2] = -1050332.0;
  scd.orbitInfo.velocityEci[0] =  5671.378;
  scd.orbitInfo.velocityEci[1] =  6718.823;
  scd.orbitInfo.velocityEci[2] = -4193.746;
  const double TxFrequency = 437.325e6f;
  scd.param.transmitterFrequency = TxFrequency;
  scd.param.ballisticCoeff = 150.0;

  tracker->setSpacecraftInfo (scd);
  return tracker;
}

void TrackerFree(Tracker t)
{
  DespatchTracker* tracker = (DespatchTracker*)t;
  delete tracker;
}

void SetTrackerGeoCoord(Tracker t, double lat, double lon, double alt)
{
  DespatchTracker* tracker = (DespatchTracker*)t;
  tracker->setObserverGeoCoord(DEG_TO_RAD(lat), DEG_TO_RAD(lon), alt);
}

int SetTargetTime(Tracker t, unsigned long time)
{
  DespatchTracker* tracker = (DespatchTracker*)t;
  return tracker->setTargetTime(time);
}

TrackerInfo GetInfo(Tracker t)
{
  DespatchTracker* tracker = (DespatchTracker*)t;
  TrackerInfo info;

  tracker->getSpacecraftDirection(&info.elevation, &info.azimuth);
  info.elevation = RAD_TO_DEG(info.elevation);
  info.azimuth = RAD_TO_DEG(info.azimuth);

  tracker->getDopplerFrequency(&info.doppler);
  tracker->getDistanceEarthCentered(&info.distance);
  tracker->getSpacecraftGeoCoord(&info.latitude, &info.longitude, &info.altitude);

  tracker->getGeometryEarthCentered(&info.declination, &info.right_ascension);
  info.declination = RAD_TO_DEG(info.declination);
  info.right_ascension = RAD_TO_DEG(info.right_ascension);

  info.doppler += 437.325e6f;

  return info;
}

const char* GetMode(Tracker t)
{
  DespatchTracker* tracker = (DespatchTracker*)t;
  string mode;
  tracker->getDespatchPhase(&mode);
  return mode.c_str();
}

void ResetSpacecraftState(Tracker t)
{
  DespatchTracker* tracker = (DespatchTracker*)t;
  tracker->resetSpacecraftState();
}

void GetNextPasses(Tracker t, double begin, double end, double interval, double* result, int len)
{
  if (len <= 0) return;

  DespatchTracker* tracker = (DespatchTracker*)t;
  PassFinder f;

  double departureUnixtime;
  tf:: convertMjdToUnixtime (&departureUnixtime, DepartureMjd);
  f.setDepartureTime (departureUnixtime);

  vector<Pass> p = f.findAll(tracker, begin, end, interval);
  int i = 0;
  for (vector<Pass>::iterator it = p.begin(); it != p.end(); ++it) {
    result[i++] = it->AOS; if (i >= len) break;
    result[i++] = it->LOS; if (i >= len) break;
    result[i++] = it->TCA; if (i >= len) break;
  }

  for (; i < len; ++i) {
    result[i++] = 0.0;
  }
}
