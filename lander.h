#pragma once
#include <string>     // To display text on the screen
#include <cmath>      // for M_PI, sin() and cos()
#include <algorithm>  // used for min() and max()
#include <sstream>    // for OSTRINGSTRING
#include "point.h"    // Where things are drawn
#include "angle.h"
#include "uiInteract.h"
#define PI 3.14159265359
using std::string;
using std::min;
using std::max; using namespace std;
class Lander {
public:
	Lander() {
		location = Point(300, 300);
		xAcc = 0;
		yAcc = 0;
		xVel = 0;
		yVel = 0;
		landerAngle = 0;
		speed = 0;
		fuel = 5000;
		time = .1;
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
		outOfFuel = copier.outOfFuel;
		time = copier.time;
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
		time = .1;
	}
public: 
	bool outOfFuel;
private:
	Point location;
	double xAcc;
	double yAcc;
	double xVel;
	double yVel;
	Angle landerAngle;
	double speed;
	int fuel;
	const double GRAVITY = -1.625;
	const double THRUSTSTRENGTH = 45000/15103 *3;
	double thrusterOn = false;
	double time;
private:
	double computeDistance(double location, double velocity, double accel, double time) const;
	double calculateVel(double velocity, double acceleration, double time) const;
	double calculateHor(Angle angle, double total) const;
	double calculateVer(Angle angle, double total) const;
	double calculateTotal(double x, double y) const;
public:
	void moveLander(const Interface *UI);
	int getFuel() const;
	Point getLocation() const;
	Angle getAngle() const;
	void loseFuel(int change);
	double getSpeed() const;

};