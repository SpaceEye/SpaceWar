#pragma once
#include <iostream>

struct Vect3
{
	float x;
	float y;
	float z;

	Vect3(float in_x = 0, float in_y = 0, float in_z = 0)
	{
		x = in_x;
		y = in_y;
		z = in_z;
	}

	inline operator float*()
	{
		return &x;
	}

	inline Vect3 operator+(const Vect3& right)
	{
		return Vect3(x + right.x, y + right.y, z + right.z);
	}

	inline Vect3 operator-(const Vect3& right)
	{
		return Vect3(x - right.x, y - right.y, z - right.z);
	}

	inline Vect3 operator*(const float& right)
	{
		return Vect3(x * right, y * right, z * right);
	}

	/*Vect3 perCCW()
	{
		return Vect3(-y, x);
	}

	Vect3 perCW()
	{
		return Vect3(y, -x);
	}

	Vect2 project(const Vect2& right)
	{
		return right*((x*right.x + y*right.y) / right.vectorLengthSquared);
	}

	Vect3 normalized()
	{
		float length = vectorLength();
		length = length > 0 ? length : 1;
		return Vect3(x / length, y / length);
	}*/

	float dot(const Vect3& right)
	{
		return x*right.x + y*right.y + z*right.z;
	}

	/*float vectorLength()
	{
		return std::sqrt(x*x + y*y);
	}

	float vectorLengthSquared()
	{
		return x*x + y*y;
	}

	Vect3 Lerp(Vect3& right, const float bata)
	{
		Vect3 alerp(0, 0), blerp(0, 0);
		alerp.x = (1 - bata)*x;
		alerp.y = (1 - bata)*y;
		blerp = alerp*bata;
		return alerp + blerp;
	}*/


};