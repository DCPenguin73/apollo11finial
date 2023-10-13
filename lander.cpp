#include <math.h>   
#include <cmath>
#include <iostream>  
#include <cassert>   
#include "lander.h"
#include "point.h"   
#include "angle.h"
#include "uiInteract.h"
#define PI 3.14159265359
using std::string;
using std::min;
using std::max;
using namespace std;


double Lander::computeDistance(double location, double velocity, double accel, double time) const {
	double newLocation = location + (velocity * time) + (0.5 * accel * (time * time));
	return newLocation;
};
double Lander::calculateVel(double velocity, double acceleration, double time) const {
	double newVelocity = velocity + (acceleration * time);
	return newVelocity;
};
double Lander::calculateHor(Angle angle, double total) const {
	double x = sin(angle.getRadians()) * total;
	return x;
};
double Lander::calculateVer(Angle angle, double total) const {
	double y = cos(angle.getRadians()) * total;
	return y;
};
double Lander::calculateTotal(double x, double y) const {
	double total;
	total = sqrt(x * x + y * y);
	return total;
};
void Lander::moveLander(const Interface *UI) {
	if (outOfFuel == false) {
		if (UI->isRight()) {
			landerAngle.setRadians(landerAngle.getRadians() - .1);
			loseFuel(1);
		}
		if (UI->isLeft()) {
			landerAngle.setRadians(landerAngle.getRadians() + .1);
			loseFuel(1);
		}
		if (UI->isUp()) {
			loseFuel(10);
			thrusterOn = true;
		}
		else {
			thrusterOn = false;
		}
	}
	if (thrusterOn == true) {
		xAcc = calculateHor(landerAngle.getRadians()+PI, THRUSTSTRENGTH);
		yAcc = calculateVer(landerAngle.getRadians(), THRUSTSTRENGTH) + GRAVITY;
	}
	else {
		xAcc = 0;
		yAcc = GRAVITY;
	}
	xVel = calculateVel(xVel, xAcc, time);
	yVel = calculateVel(yVel, yAcc, time);
	speed = calculateTotal(xVel, yVel);
	location = Point(
		computeDistance(location.getX(), xVel, xAcc, time),
		computeDistance(location.getY(), yVel, yAcc, time)
	);
};
int Lander::getFuel() const {
	return fuel;
};
Point Lander::getLocation() const {
	return location;
}
Angle Lander::getAngle() const {
	return landerAngle;
}
void Lander::loseFuel(int change){
	fuel = fuel - change;
	if (fuel <= 0) {
		fuel = 0;
		outOfFuel = true;
	}
}