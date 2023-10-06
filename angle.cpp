#pragma once

#define TWO_PI 6.28318530718

#include <math.h>   
#include <iostream>  
#include <cassert>   
#include "angle.h"
using namespace std;


	double Angle::getDegrees() const {
		return convertToDegrees(radians);
	}
	double Angle::getRadians() const {
		return radians;
	}
	void Angle::setDegrees(double angleD) {
		radians = convertToRadians(angleD);
	}
	void Angle::setRadians(double angleR) {
		radians = normalize(angleR);
	}
	void Angle::display(ostream& out) const {
		out.setf(ios::fixed);     // "fixed" means don't use scientific notation
		out.setf(ios::showpoint); // "showpoint" means always show the decimal point
		out.precision(1);         // Set the precision to 1 decimal place of accuracy.;
		out << convertToDegrees(radians) << "degrees";
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
	double Angle::convertToDegrees(double angleR) const {
		double d;
		d = (360 * normalize(angleR)) / TWO_PI;
		return d;
	}
	double Angle::convertToRadians(double angleD) const {
		double r;
		r = (TWO_PI * angleD) / 360;
		r = normalize(r);
		return r;
	}


