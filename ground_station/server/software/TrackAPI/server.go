package main

import (
	"bytes"
	"encoding/json"
	"errors"
	"fmt"
	"github.com/go-martini/martini"
	"net/http"
	"net/url"
	"strconv"
)

type TrackArguments struct {
	Time          int64
	Lat, Lon, Alt float64
}

type TrackRangeArguments struct {
	BeginTime     int64
	EndTime       int64
	Interval      int64
	Lat, Lon, Alt float64
}

type TrackInfo struct {
	Time           int64   `json:"time"`
	Elevation      float64 `json:"elevation"`
	Azimuth        float64 `json:"azimuth"`
	Frequency      int64   `json:"frequency"`
	Distance       int64   `json:"distance"`
	Declination    float64 `json:"declination"`
	RightAscension float64 `json:"right_ascension"`
	Phase          string  `json:"phase"`
}

type PassInfo struct {
	AOS TrackInfo `json:"aos"`
	TCA TrackInfo `json:"tca"`
	LOS TrackInfo `json:"los"`
}

func getTrackInfo(req *http.Request, tracker *Tracker) (TrackInfo, error) {
	var info TrackInfo

	args := getTrackArguments(req)
	if args == nil {
		return info, errors.New("incorrect parameter")
	}

	tracker.ResetSpacecraftState()
	tracker.SetGeoCoord(args.Lat, args.Lon, args.Alt)

	if tracker.SetTargetTime(args.Time) != 0 {
		return info, errors.New("incorrect target time")
	}

	info = tracker.GetInfo()

	return info, nil
}

func getTrackRangeInfo(req *http.Request, tracker *Tracker) ([]TrackInfo, error) {

	args := getTrackRangeArguments(req)
	if args == nil {
		return nil, errors.New("incorrect parameter")
	}

	tracker.ResetSpacecraftState()
	tracker.SetGeoCoord(args.Lat, args.Lon, args.Alt)

	ary := make([]TrackInfo, 0)
	for time := args.BeginTime; time <= args.EndTime; time += args.Interval {
		if tracker.SetTargetTime(time) == 0 {
			t := tracker.GetInfo()
			ary = append(ary, t)
		} else {
			return nil, errors.New("incorrect target time")
		}
	}

	return ary, nil
}

func getPasses(req *http.Request, tracker *Tracker) ([]PassInfo, error) {

	args := getTrackArguments(req)
	if args == nil {
		return nil, errors.New("incorrect parameter")
	}

	tracker.ResetSpacecraftState()
	tracker.SetGeoCoord(args.Lat, args.Lon, args.Alt)

	p := tracker.GetNextPasses(float64(args.Time), float64(args.Time+60*60*24*5), 120.0)
	return p, nil
}

func main() {
	m := martini.Classic()
	tracker := TrackerNew()

	m.Get("/track.json", func(res http.ResponseWriter, req *http.Request) {
		res.Header().Set("Content-Type", "application/json")

		var t interface{}
		t, err := getTrackInfo(req, tracker)
		if err == nil {
			res.WriteHeader(200)
		} else {
			res.WriteHeader(400)
			t = struct {
				Error string `json:"error"`
			}{Error: err.Error()}
		}

		js, _ := json.Marshal(t)

		var out bytes.Buffer
		json.Indent(&out, js, "", "  ")
		out.WriteTo(res)
	})

	m.Get("/track.csv", func(res http.ResponseWriter, req *http.Request) {
		res.Header().Set("Content-Type", "text/plain")

		t, err := getTrackInfo(req, tracker)

		if err == nil {
			res.WriteHeader(200)
			str := "time, elevation, azimuth, frequency, distance, phase\r\n"
			str += fmt.Sprintf("%v, %v, %v, %v, %v, %v", t.Time, t.Elevation, t.Azimuth, t.Frequency, t.Distance, t.Phase)
			str += "\r\n"
			res.Write([]byte(str))
		} else {
			res.WriteHeader(400)
			res.Write([]byte("error: " + err.Error() + "\r\n"))
		}
	})

	m.Get("/track_range.json", func(res http.ResponseWriter, req *http.Request) {
		res.Header().Set("Content-Type", "application/json")

		var t interface{}
		t, err := getTrackRangeInfo(req, tracker)

		if err == nil {
			res.WriteHeader(200)
		} else {
			res.WriteHeader(400)
			t = struct {
				Error string `json:"error"`
			}{Error: err.Error()}
		}

		js, _ := json.Marshal(t)
		var out bytes.Buffer
		json.Indent(&out, js, "", "  ")
		out.WriteTo(res)
	})

	m.Get("/track_range.csv", func(res http.ResponseWriter, req *http.Request) {
		res.Header().Set("Content-Type", "text/plain")

		ary, err := getTrackRangeInfo(req, tracker)

		if err == nil {
			res.WriteHeader(200)
			str := "time, elevation, azimuth, frequency, distance, phase\r\n"

			for _, t := range ary {
				str += fmt.Sprintf("%v, %v, %v, %v, %v, %v", t.Time, t.Elevation, t.Azimuth, t.Frequency, t.Distance, t.Phase) + "\r\n"
			}

			res.Write([]byte(str))
		} else {
			res.WriteHeader(400)
			res.Write([]byte("error: " + err.Error() + "\r\n"))
		}
	})

	m.Get("/pass.json", func(res http.ResponseWriter, req *http.Request) {
		res.Header().Set("Content-Type", "application/json")

		var t interface{}
		t, err := getPasses(req, tracker)
		if err == nil {
			res.WriteHeader(200)
		} else {
			res.WriteHeader(400)
			t = struct {
				Error string `json:"error"`
			}{Error: err.Error()}
		}

		js, _ := json.Marshal(t)

		var out bytes.Buffer
		json.Indent(&out, js, "", "  ")
		out.WriteTo(res)
	})

	m.Get("/pass.csv", func(res http.ResponseWriter, req *http.Request) {
		res.Header().Set("Content-Type", "text/plain")

		p, err := getPasses(req, tracker)

		if err == nil {
			res.WriteHeader(200)
			str := "state, time, elevation, azimuth, frequency, distance, phase\r\n"
			for _, t := range p {
				str += fmt.Sprintf("AOS, %v, %v, %v, %v, %v, %v", t.AOS.Time, t.AOS.Elevation, t.AOS.Azimuth, t.AOS.Frequency, t.AOS.Distance, t.AOS.Phase)
				str += "\r\n"
				str += fmt.Sprintf("TCA, %v, %v, %v, %v, %v, %v", t.TCA.Time, t.TCA.Elevation, t.TCA.Azimuth, t.TCA.Frequency, t.TCA.Distance, t.TCA.Phase)
				str += "\r\n"
				str += fmt.Sprintf("LOS, %v, %v, %v, %v, %v, %v", t.LOS.Time, t.LOS.Elevation, t.LOS.Azimuth, t.LOS.Frequency, t.LOS.Distance, t.LOS.Phase)
				str += "\r\n"
			}
			res.Write([]byte(str))
		} else {
			res.WriteHeader(400)
			res.Write([]byte("error: " + err.Error() + "\r\n"))
		}
	})

	m.RunOnAddr(":9200")
}

func getTrackArguments(req *http.Request) *TrackArguments {
	args := TrackArguments{}

	u, err := url.Parse(req.RequestURI)
	if err != nil {
		return nil
	}
	query := u.Query()

	if val, ok := query["time"]; ok {
		i, err := strconv.ParseInt(val[0], 10, 64)
		if err != nil {
			return nil
		} else {
			args.Time = i
		}
	} else {
		return nil
	}

	if val, ok := query["lat"]; ok {
		i, err := strconv.ParseFloat(val[0], 64)
		if err != nil {
			return nil
		} else {
			args.Lat = i
		}
	} else {
		return nil
	}

	if val, ok := query["lon"]; ok {
		i, err := strconv.ParseFloat(val[0], 64)
		if err != nil {
			return nil
		} else {
			args.Lon = i
		}
	} else {
		return nil
	}

	if val, ok := query["alt"]; ok {
		i, err := strconv.ParseFloat(val[0], 64)
		if err != nil {
			return nil
		} else {
			args.Alt = i
		}
	} else {
		return nil
	}

	return &args
}

func getTrackRangeArguments(req *http.Request) *TrackRangeArguments {
	args := TrackRangeArguments{}

	u, err := url.Parse(req.RequestURI)
	if err != nil {
		return nil
	}
	query := u.Query()

	if val, ok := query["begin"]; ok {
		i, err := strconv.ParseInt(val[0], 10, 64)
		if err != nil {
			return nil
		} else {
			args.BeginTime = i
		}
	} else {
		return nil
	}

	if val, ok := query["end"]; ok {
		i, err := strconv.ParseInt(val[0], 10, 64)
		if err != nil {
			return nil
		} else {
			args.EndTime = i
		}
	} else {
		return nil
	}

	if val, ok := query["interval"]; ok {
		i, err := strconv.ParseInt(val[0], 10, 64)
		if err != nil {
			return nil
		} else {
			args.Interval = i
		}
	} else {
		return nil
	}

	if val, ok := query["lat"]; ok {
		i, err := strconv.ParseFloat(val[0], 64)
		if err != nil {
			return nil
		} else {
			args.Lat = i
		}
	} else {
		return nil
	}

	if val, ok := query["lon"]; ok {
		i, err := strconv.ParseFloat(val[0], 64)
		if err != nil {
			return nil
		} else {
			args.Lon = i
		}
	} else {
		return nil
	}

	if val, ok := query["alt"]; ok {
		i, err := strconv.ParseFloat(val[0], 64)
		if err != nil {
			return nil
		} else {
			args.Alt = i
		}
	} else {
		return nil
	}

	return &args
}
