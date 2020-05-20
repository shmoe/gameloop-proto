#include "Vector.hpp"

#include <math.h>
#define PI 3.14159265

Vector::Vector(){
	magnitude=0.0;
	theta=0.0;
}

Vector::Vector(float magnitude, float theta){
	this->magnitude = magnitude;
	this->theta = theta * PI / 180;
}

void Vector::setMagnitude(float new_magni){
	magnitude = new_magni;
}
float Vector::getMagnitude(){
	return magnitude;
}

void Vector::setTheta(float new_theta){
	theta = new_theta * PI / 180;
}
float Vector::getTheta(){
	return theta;
}

void Vector::setByComponents(float x, float y){
	theta = atan2(y,x);
	magnitude = sqrt(x*x + y*y);
}
float Vector::getX(){
	return magnitude * cos(theta);
}
float Vector::getY(){
	return magnitude * sin(theta);
}

