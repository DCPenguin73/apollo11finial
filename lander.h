/***********************************************************************
*    Lander: represents the lander we control in the moon lander simulator.
 * Author:
 *    Cayden Lords and Daniel Carr
 * Summary:
 *    Where the lander is and how it flies.
 ************************************************************************/

#pragma once
#include <string>     // To display text on the screen
#include <cmath>      // for M_PI, sin() and cos()
#include <algorithm>  // used for min() and max()
#include <sstream>    // for OSTRINGSTRING
#include "point.h"    // Where things are drawn
#include "angle.h"
#define PI 3.14159265359
using std::string;
using std::min;
using std::max; using namespace std;

/***********************************************************
 * LANDER
 * The lander class
 ***********************************************************/
class Lander {
public:
	//default constructor
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
	//copier constructor
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
	//Parameterized constructor
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
	bool outOfFuel;                                // Whether the lander is out of fuel or not
private:
	Point location;                                // Where the fuel is 
	double xAcc;                                   // The horizontal acceleration of the lander
	double yAcc;                                   // The vertical acceleration of the lander
	double xVel;                                   // The horizontal velocity of the lander
	double yVel;                                   // The vertical velocity of the lander
	Angle landerAngle;                             // What angle the lander is facing at
	double speed;                                  // The overall velocity or speed of the lander
	int fuel;                                      // How much fuel the lander has left
	const double GRAVITY = -1.625;                 // The amount of gravity pulling on the lander
	const double THRUSTSTRENGTH = 45000/15103 *3;  // How strong the thrust on the lander is
	double thrusterOn = false;                     // Whether the thruster is on or not
	double time;                                   // How long between calculations of the lander moving
private:
	// calculate the distance moved based on velocity and acceleration
	double computeDistance(double location, double velocity, double accel, double time) const;
	
	// calculates the new velocity after a segment of time
	double calculateVel(double velocity, double acceleration, double time) const;
	
	// calculates the horizontal movement from the total movement and the angle
	double calculateHor(Angle angle, double total) const;
	
	// calculates the vertical movement from the total movement and the angle
	double calculateVer(Angle angle, double total) const;

	// calculate the total movment based on the x and y movement.
	double calculateTotal(double x, double y) const;

public:
	// calculates where the lander should move and how fast it's moving. 
	void moveLander(bool upPressed, bool leftPressed, bool rightPressed);
	
	// returns how much fuel is left
	int getFuel() const;

	// returns where the lander currently is
	Point getLocation() const;

	// returns what direction the lander is facing
	Angle getAngle() const;

	// removes fuel as the player uses it 
	void loseFuel(int change);

	//returns how fast the speeder is moving overall
	double getSpeed() const;

};