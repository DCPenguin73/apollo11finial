#pragma once

#define TWO_PI 6.28318530718

#include <string>     // To display text on the screen
#include <cmath>      // for M_PI, sin() and cos()
#include <algorithm>  // used for min() and max()
#include <sstream>    // for OSTRINGSTRING
#include "point.h"    // Where things are drawn
using std::string;
using std::min;
using std::max;
#include "angle.h"
using namespace std;



	double Angle::getRadians() const {
		return radians;
	}
	void Angle::setRadians(double angleR) {
		radians = normalize(angleR);
	}
	double Angle::normalize(double angleR) const {
		double r = angleR;
		while (r < 0) {
			r = TWO_PI + r;
		}
		while (r > TWO_PI) {
			r = r - TWO_PI;
		}
		return r;
	}



