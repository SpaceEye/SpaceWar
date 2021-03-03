#pragma once
#include <iostream>
#include "Vect3.h"

struct Matrix3
{
private:
	Vect3 v1;
	Vect3 v2;
	Vect3 v3;
public:
	Matrix3()
	{
		v1 = Vect3(1, 0, 0);
		v2 = Vect3(0, 1, 0);
		v3 = Vect3(0, 0, 1);
	}

	Matrix3(const Vect3& col1, const Vect3& col2, const Vect3& col3)
	{
		v1 = col1;
		v2 = col2;
		v3 = col3;
	}

	inline Vect3 operator*(const Vect3& v)
	{
		Vect3 result;
		result.x = v.x*v1.x + v.y*v1.y + v.z*v1.z;
		result.y = v.x*v2.x + v.y*v2.y + v.z*v2.z;
		result.z = v.x*v3.x + v.y*v3.y + v.z*v3.z;

		return result;
	}

	inline Matrix3 operator*(const Matrix3& m)
	{
		Vect3 _v1, _v2, _v3;
		_v1.x = m.v1.x*v1.x + m.v2.x*v1.y + m.v3.x*v1.z;
		_v1.y = m.v1.y*v1.x + m.v2.y*v1.y + m.v3.y*v1.z;
		_v1.z = m.v1.z*v1.x + m.v2.z*v1.y + m.v3.z*v1.z;

		_v2.x = m.v1.x*v2.x + m.v2.x*v2.y + m.v3.x*v2.z;
		_v2.y = m.v1.y*v2.x + m.v2.y*v2.y + m.v3.y*v2.z;
		_v2.z = m.v1.z*v2.x + m.v2.z*v2.y + m.v3.z*v2.z;

		_v3.x = m.v1.x*v3.x + m.v2.x*v3.y + m.v3.x*v3.z;
		_v3.y = m.v1.y*v3.x + m.v2.y*v3.y + m.v3.y*v3.z;
		_v3.z = m.v1.z*v3.x + m.v2.z*v3.y + m.v3.z*v3.z;

		return Matrix3(_v1, _v2, _v3);
	}

	inline Matrix3 operator+(const Matrix3& m)
	{
		return Matrix3(v1 + m.v1, v2 + m.v2, v3 + m.v3);
	}

	inline Matrix3 operator*(const float scalar)
	{
		return Matrix3(v1*scalar, v2*scalar, v3*scalar);
	}

	static Matrix3 RotationX(float angle)
	{
		return Matrix3(
			Vect3(1, 0, 0),
			Vect3(0, std::cos(angle), -std::sin(angle)),
			Vect3(0, std::sin(angle), std::cos(angle))
		);
	}

	static Matrix3 RotationY(float angle)
	{
		return Matrix3(
			Vect3(std::cos(angle), 0, std::sin(angle)),
			Vect3(0, 1, 0),
			Vect3(-std::sin(angle), 0, std::cos(angle))
		);
	}

	static Matrix3 RotationZ(float angle)
	{
		return Matrix3(
			Vect3(std::cos(angle), -std::sin(angle), 0),
			Vect3(std::sin(angle), std::cos(angle), 0),
			Vect3(0, 0, 1)
		);
	}

	static Matrix3 Translate(float x, float y)
	{
		return Matrix3(
			Vect3(1, 0, x),
			Vect3(0, 1, y),
			Vect3(0, 0, 1)
		);

	}

	

	/*static Matrix2 Scale(float scale)
	{
	return Matrix2(
	Vect2(scale, scale),
	Vect2(scale, scale)
	);
	}*/
};