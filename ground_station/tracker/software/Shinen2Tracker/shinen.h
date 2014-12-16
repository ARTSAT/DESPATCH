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
#ifndef SHINEN_H_
#define SHINEN_H_

#include "tf.h"
#include "tracker.h"

#include <string>

class Shinen2Tracker : public SpacecraftTracker {
	public:
		Shinen2Tracker (void);
		Shinen2Tracker (double departureMjd ,SCDRec const& scd);
		~Shinen2Tracker (void);
		
		void setDepartureTime (double departureMjd);
		void getDepartureTime (double* departureMjd) const;
		
		int setTargetTime (double unixtime);
		
		void test (double unixtime_s, double unixtime_e, double outputDt);
	
	private:
		static const double SecondsRadioStop_;
		
		double departureMjd_;
		void calcSecondsFromDeparture (double* secondsFromDeparture) const;
};

#endif