package main

/*
#cgo LDFLAGS: -lsctracker -LSCTracker -lm -lstdc++
#include "SCTracker/c.h"
*/
import "C"

type Tracker struct {
	t    C.Tracker
	time int64
}

func TrackerNew() *Tracker {
	return &Tracker{C.TrackerNew(), 0}
}

func TrackerFree(p *Tracker) {
	C.TrackerFree(p.t)
}

func (p *Tracker) SetGeoCoord(lat float64, lon float64, alt float64) {
	C.SetTrackerGeoCoord(p.t, C.double(lat), C.double(lon), C.double(alt))
}

func (p *Tracker) SetTargetTime(time int64) int {
	p.time = time
	return int(C.SetTargetTime(p.t, C.ulong(time)))
}

func (p *Tracker) GetInfo() TrackInfo {
	info := C.GetInfo(p.t)
	phase := C.GoString(C.GetMode(p.t))
	return TrackInfo{
		Time:           p.time,
		Elevation:      float64(info.elevation),
		Azimuth:        float64(info.azimuth),
		Frequency:      int64(info.doppler),
		Distance:       int64(info.distance),
		Declination:    float64(info.declination),
		RightAscension: float64(info.right_ascension),
		Phase:          phase,
	}
}

func (p *Tracker) ResetSpacecraftState() {
	C.ResetSpacecraftState(p.t)
}

func (p *Tracker) GetNextPasses(begin float64, end float64, interval float64) []PassInfo {
	var ary []PassInfo
	var result [10 * 3]float64
	C.GetNextPasses(p.t, C.double(begin), C.double(end), C.double(interval), (*C.double)(&result[0]), C.int(len(result)))
	for i := 0; i < len(result)/3; i++ {
		aos := result[i*3+0]
		los := result[i*3+1]
		tca := result[i*3+2]
		if aos == 0.0 {
			break
		}
		var pass PassInfo
		p.SetTargetTime(int64(aos))
		pass.AOS = p.GetInfo()
		p.SetTargetTime(int64(los))
		pass.LOS = p.GetInfo()
		p.SetTargetTime(int64(tca))
		pass.TCA = p.GetInfo()
		ary = append(ary, pass)
	}
	return ary
}
