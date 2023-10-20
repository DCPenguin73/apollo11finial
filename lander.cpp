/***********************************************************************
 * Source File:
 *    Lander: represents the lander we control in the moon lander simulator. 
 * Author:
 *    Cayden Lords and Daniel Carr
 * Summary:
 *    Where the lander is and how it flies. 
 ************************************************************************/


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

/************************************************************************
 * COMPUTE DISTANCE
 * Calculate how far the lander would move
 ************************************************************************/
double Lander::computeDistance(double location, double velocity, double accel, double time) const {
	double newLocation = location + (velocity * time) + (0.5 * accel * (time * time));
	return newLocation;
};

/************************************************************************
 * CALCULATE VELOCITY
 * Calculate the new velocity of the lander
 ************************************************************************/
double Lander::calculateVel(double velocity, double acceleration, double time) const {
	double newVelocity = velocity + (acceleration * time);
	return newVelocity;
};

/************************************************************************
 * CALCULATE HORIZONTAL
 * Calculate an x variable based on the total and the angle
 ************************************************************************/
double Lander::calculateHor(Angle angle, double total) const {
	double x = sin(angle.getRadians()) * total;
	return x;
};

/************************************************************************
 * CALCULATE HORIZONTAL
 * Calculate an y variable based on the total and the angle
 ************************************************************************/
double Lander::calculateVer(Angle angle, double total) const {
	double y = cos(angle.getRadians()) * total;
	return y;
};

/************************************************************************
 * CALCULATE TOTAL
 * Calculate calculate the total based on the x and y ranges
 ************************************************************************/
double Lander::calculateTotal(double x, double y) const {
	double total;
	total = sqrt(x * x + y * y);
	return total;
};

/************************************************************************
 * MOVE LANDER
 * Updates all the variables of the lander and moves it to its new location
 ************************************************************************/
void Lander::moveLander(bool upPressed, bool leftPressed, bool rightPressed) {
	
	// If the fuel isn't out, recieve the user's controls. 
	if (outOfFuel == false) {
		if (rightPressed) {
			landerAngle.setRadians(landerAngle.getRadians() - .1);
			loseFuel(1);
		}
		if (leftPressed) {
			landerAngle.setRadians(landerAngle.getRadians() + .1);
			loseFuel(1);
		}
		if (upPressed) {
			loseFuel(10);
			thrusterOn = true;
		}
		else {
			thrusterOn = false;
		}
	}

	// Update the acceleration based on whether the thruster is on 
	if (thrusterOn == true) {
		xAcc = calculateHor(landerAngle.getRadians()+PI, THRUSTSTRENGTH);
		yAcc = calculateVer(landerAngle.getRadians(), THRUSTSTRENGTH) + GRAVITY;
	}
	else {
		xAcc = 0;
		yAcc = GRAVITY;
	}

	// Update the horizontal and verical speed
	xVel = calculateVel(xVel, xAcc, time);
	yVel = calculateVel(yVel, yAcc, time);

	// Use the new speeds to update the overall speed
	speed = calculateTotal(xVel, yVel);

	// Move the lander based on the speed it is moving
	location = Point(
		computeDistance(location.getX(), xVel, xAcc, time),
		computeDistance(location.getY(), yVel, yAcc, time)
	);
};

/************************************************************************
 * GET FUEL
 * Return the current amount of fuel
 ************************************************************************/
int Lander::getFuel() const {
	return fuel;
};

/************************************************************************
 * GET LOCATION
 * Return the current location
 ************************************************************************/
Point Lander::getLocation() const {
	return location;
}

/************************************************************************
 * GET LANDER
 * Return the current angle of the lander
 ************************************************************************/
Angle Lander::getAngle() const {
	return landerAngle;
}

/************************************************************************
 * LOSE FUEL
 * Reduce the amount of fuel the lander has
 ************************************************************************/
void Lander::loseFuel(int change){
	fuel = fuel - change;
	if (fuel <= 0) {
		fuel = 0;
		outOfFuel = true;
	}
}

/************************************************************************
 * GET SPEED
 * Return the current overall speed of the lander
 ************************************************************************/
double Lander::getSpeed() const {
	return speed;
}