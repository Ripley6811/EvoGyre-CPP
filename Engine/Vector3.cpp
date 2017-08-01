#include "Vector3.h"

#include <cmath>

Vector3& Vector3::operator=(const Vector3& other)
{
	x = other.x;
	y = other.y;
	z = other.z;

	return *this;
}

Vector3 Vector3::operator+(const Vector3& other)
{
	Vector3 ret;
	ret.x = x + other.x;
	ret.y = y + other.y;
	ret.z = z + other.z;
	return ret;
}

Vector3 Vector3::operator-(const Vector3& other)
{
	Vector3 ret;
	ret.x = x - other.x;
	ret.y = y - other.y;
	ret.z = z - other.z;
	return ret;
}

Vector3 Vector3::operator*(const Vector3& other)
{
	Vector3 ret;
	ret.x = x * other.x;
	ret.y = y * other.y;
	ret.z = z * other.z;
	return ret;
}

Vector3 Vector3::operator*(float _x)
{
	Vector3 ret;
	ret.x = x * _x;
	ret.y = y * _x;
	ret.z = z * _x;
	return ret;
}

bool Vector3::operator==(const Vector3& other)
{
	return (x == other.x && y == other.y && z == other.z);
}

bool Vector3::operator!=(const Vector3& other)
{
	return !operator==(other);
}

Vector3 Vector3::setLength(float len) {
	return setLength2(len * len);
}

Vector3 Vector3::setLength2(float _len2) {
	float oldLen2 = len2();
	return (oldLen2 == 0 || oldLen2 == _len2)
		? Vector3(x, y, z)
		: scl((float) std::pow(_len2 / oldLen2, 0.5));
}

Vector3 Vector3::scl(float scalar) {
	x *= scalar;
	y *= scalar;
	z *= scalar;
	return Vector3(x, y, z);
}

float Vector3::len() {
	return (float)pow(x * x + y * y, 0.5);
}

float Vector3::len2() {
	return x * x + y * y;
}
