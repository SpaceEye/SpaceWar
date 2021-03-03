#pragma once
#include <iostream>
#include "Vect2.h"

struct Matrix2
{
private:
	Vect2 v1;
	Vect2 v2;
public:
	Matrix2()
	{
		v1 = Vect2(1, 0);
		v2 = Vect2(0, 1);
	}

	Matrix2(const Vect2& row1, const Vect2& row2)
	{
		v1 = row1;
		v2 = row2;
	}

	inline Vect2 operator*(const Vect2& v)
	{
		Vect2 result;
		result.x = v.x*v1.x + v.y*v1.y;
		result.y = v.x*v2.x + v.y*v2.y;

		return result;
	}

	inline Matrix2 operator*(const Matrix2& m)
	{
		Vect2 _v1, _v2;
		_v1.x = m.v1.x*v1.x + m.v2.x*v1.y;
		_v1.y = m.v1.y*v1.x + m.v2.y*v1.y;
		_v2.x = m.v1.x*v2.x + m.v2.x*v2.y;
		_v2.y = m.v1.x*v2.x + m.v2.y*v2.y;

		return Matrix2(_v1, _v2);
	}

	inline Matrix2 operator+(const Matrix2& m)
	{
		return Matrix2(v1 + m.v1, v2 + m.v2);
	}

	inline Matrix2 operator*(const float scalar)
	{
		return Matrix2(v1*scalar, v2*scalar);
	}

	static Matrix2 Rotation(float angle)
	{
		return Matrix2(
			Vect2(std::cos(angle), -std::sin(angle)),
			Vect2(std::sin(angle), std::cos(angle))
		);
	}

	Vect2 Get_V1()
	{
		return Vect2(v1.x, v2.x);
	}

	Vect2 Get_V2()
	{
		return Vect2(v1.y, v2.y);
	}

	/*static Matrix2 Scale(float scale)
	{
	return Matrix2(
	Vect2(scale, scale),
	Vect2(scale, scale)
	);
	}*/
};