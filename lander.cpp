#include <math.h>   
#include <iostream>  
#include <cassert>   
#include "lander.h"
#include "point.h"   
#include "angle.h"
using std::string;
using std::min;
using std::max;
using namespace std;


double Lander::computeDistance(double speed, double velocity, double accel, double time) const {
	//STUB FUNCTION SO COOL YEAH
	return 0.0;
};
double Lander::calculateAcc(double force, double mass) const {
	//STUB FUNCTION SO COOL YEAH
	return 0.0;
};
double Lander::calculateVel(double velocity, double acceleration, double time) const {
	//STUB FUNCTION SO COOL YEAH
	return 0.0;
};
double Lander::calculateHor(Angle angle, double total) const {
	//STUB FUNCTION SO COOL YEAH
	return 0.0;
};
double Lander::calculateVer(Angle angle, double total) const {
	//STUB FUNCTION SO COOL YEAH
	return 0.0;
};
double Lander::calculateTotal(double x, double y) const {
	//STUB FUNCTION SO COOL YEAH
	return 0.0;
};
void Lander::moveLander() {
	//STUB FUNCTION SO COOL YEAH
};
void Lander::setFuel(int change) {
	//STUB FUNCTION SO COOL YEAH
};
int Lander::getFuel() const {
	//STUB FUNCTION SO COOL YEAH
	return 0;
};