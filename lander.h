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
public:
	Lander() {
		location = Point(0, 0);
		xAcc = 0;
		yAcc = 0;
		xVel = 0;
		yVel = 0;
		landerAngle = Angle(0);
		speed = 0;
		fuel = 5000;
	}
	Lander(const Lander& copier) {
		location = copier.location;
		xAcc = copier.xAcc;
		yAcc = copier.yAcc;
		xVel = copier.xVel;
		yVel = copier.yVel;
		landerAngle = copier.landerAngle;
		speed = copier.speed;
		fuel = copier.fuel;
		bool outOfFuel = copier.outOfFuel;
	}
	Lander(Point inLocation, double inXAcc, double inYAcc, double inXVel, double inYVel, Angle inLanderAngle, double inSpeed) {
		location = inLocation;
		xAcc = inXAcc;
		yAcc = inYAcc;
		xVel = inXVel;
		yVel = inYVel;
		landerAngle = inLanderAngle;
		speed = inSpeed;
		fuel = 5000;
		outOfFuel = false;
	}
private:
	Point location;
	double xAcc;
	double yAcc;
	double xVel;
	double yVel;
	Angle landerAngle;
	double speed;
	int fuel;
	const double GRAVITY = 10;
	double THRUSTSTRENGTH = 10;
	bool outOfFuel;
private:
	double computeDistance(double speed, double velocity, double accel, double time) const;
	double calculateAcc(double force, double mass) const;
	double calculateVel(double velocity, double acceleration, double time) const;
	double calculateHor(Angle angle, double total) const;
	double calculateVer(Angle angle, double total) const;
	double calculateTotal(double x, double y) const;
public:
	void moveLander();
	void setFuel(int change);
	int getFuel() const;
};