#ifndef __POLAR_VECTOR_HPP__
#define __POLAR_VECTOR_HPP__
//TODO: see if double is needed for better granularity
class Vector{
	float magnitute;
	float theta;
	public:
	float getMagnitude();
	float getTheta();
	float getX();
	float getY();
};
#endif//__MATH_VECTOR_HPP__