#ifndef __POLAR_VECTOR_HPP__
#define __POLAR_VECTOR_HPP__
//TODO: see if double is needed for better granularity
class Vector{
	float magnitude;
	float theta;

	public:
		Vector();
		Vector(float magnitude, float theta);
		void setMagnitude(float);
		float getMagnitude();
		void setTheta(float);
		float getTheta();

		void setByComponents(float,float);
		float getX();
		float getY();
};
#endif//__MATH_VECTOR_HPP__