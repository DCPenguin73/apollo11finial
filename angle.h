#pragma once

#define TWO_PI 6.28318530718

#include <math.h>    // for floor()
#include <iostream>  // for cout
#include <cassert>   // for assert()
using namespace std;

class TestAngle;

/************************************
 * ANGLE
 ************************************/
class Angle
{
	friend TestAngle;
private:
	double radians;
public:
	Angle()
	{
		radians = 0.0;
	}
	Angle(const Angle& copier)
	{
		radians = copier.radians;
	}
	Angle(double inputDeg)
	{
		radians = convertToRadians(inputDeg);
	}
public:
	double getDegrees() const;
	double getRadians() const;
	void setDegrees(double angleD);
	void setRadians(double angleR);
	void display(ostream& out) const;
private:
	double normalize(double angleR) const;
	double convertToDegrees(double angleR) const;
	double convertToRadians(double angleD) const;
};


