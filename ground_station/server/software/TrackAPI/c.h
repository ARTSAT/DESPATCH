#ifdef __cplusplus
extern "C" {
#endif

  typedef struct {
    double elevation, azimuth, doppler, distance;
    double latitude, longitude, altitude;
    double declination, right_ascension;
  } TrackerInfo;

  typedef void* Tracker;
  Tracker TrackerNew(void);
  void TrackerFree(Tracker);
  void SetTrackerGeoCoord(Tracker t, double lat, double lon, double alt);
  int SetTargetTime(Tracker t, unsigned long time);
  TrackerInfo GetInfo(Tracker t);
  const char* GetMode(Tracker t);
  void ResetSpacecraftState(Tracker t);
  void GetNextPasses(Tracker t, double begin, double end, double interval, double *result, int len);

#ifdef __cplusplus
}
#endif
