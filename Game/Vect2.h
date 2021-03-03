#pragma once
#include <iostream>

struct Vect2
{
	float x;
	float y;

	Vect2(float in_x = 0, float in_y = 0)
	{
		x = in_x;
		y = in_y;
	}

	inline operator float*()
	{
		return &x;
	}

	inline Vect2 operator+(const Vect2& right)
	{
		return Vect2(x + right.x, y + right.y);
	}

	inline Vect2 operator-(const Vect2& right)
	{
		return Vect2(x - right.x, y - right.y);
	}

	inline Vect2 operator*(const float& right)
	{
		return Vect2(x * right, y * right);
	}

	Vect2 perCCW()		//逆时针旋转
	{
		return Vect2(-y, x);
	}

	Vect2 perCW()		//顺时针旋转
	{
		return Vect2(y, -x);
	}

	//Vect2 project(const Vect2& right)
	//{
	//	return right*((x*right.x + y*right.y) / right.vectorLengthSquared);
	//}

	Vect2 normalized()
	{
		float length = vectorLength();
		length = length > 0 ? length : 1;
		return Vect2(x / length, y / length);
	}

	float dot(const Vect2& right)
	{
		return x*right.x + y*right.y;
	}

	float vectorLength()
	{
		return std::sqrt(x*x + y*y);
	}

	float vectorLengthSquared()
	{
		return x*x + y*y;
	}

	Vect2 Lerp(Vect2& right, const float bata)
	{
		Vect2 alerp(0,0), blerp(0,0);
		alerp.x = (1 - bata)*x;
		alerp.y = (1 - bata)*y;
		blerp = alerp*bata;
		return alerp + blerp;
	}


};