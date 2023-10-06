#pragma once
#include <string>     // To display text on the screen
#include <cmath>      // for M_PI, sin() and cos()
#include <algorithm>  // used for min() and max()
#include <sstream>    // for OSTRINGSTRING
#include "point.h"    // Where things are drawn
#include "angle.h"
using std::string;
using std::min;
using std::max; using namespace std;
class Lander {
private:
	Point location;
	double xAcc;
	double yAcc;
	double xVel;
	double yVel;
	Angle angle;
	double speed;
	int fuel;
	const double GRAVITY;
	const double THRUST;
	bool outOfFuel;
public:
	double computeDistance(double speed, double velocity, double accel, double time) const;
	double calculateAcc();
	double calculateVel();
	double calculateHor();
	double calculateVer();
};