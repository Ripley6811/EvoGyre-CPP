#ifndef _VECTOR3
#define _VECTOR3

class Vector3
{
public:
	float x;
	float y;
	float z;

	Vector3() : Vector3(0, 0, 0) {}
	Vector3(float _x) : Vector3(_x, _x, _x) {}
	Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
	Vector3(const Vector3& vec) : x(vec.x), y(vec.y), z(vec.z) {}
	~Vector3() {};

	Vector3& operator=(const Vector3& other);
	Vector3 operator+(const Vector3& other);
	Vector3 operator-(const Vector3& other);
	Vector3 operator*(const Vector3& other);
	Vector3 operator*(float _x);

	bool operator==(const Vector3& other);
	bool operator!=(const Vector3& other);

	Vector3 setLength(float len);

	Vector3 setLength2(float _len2);

	Vector3 scl(float scalar);

	float len();

	float len2();
};

#endif