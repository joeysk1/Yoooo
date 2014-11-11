#include <cmath>
#include <algorithm>
#include "../include/vector.h"

using namespace std;

vec2::vec2()
{
	x = 0.0f;
	y = 0.0f;
}

vec2::vec2(float p1, float p2)
{
	x = p1;
	y = p2;
}

vec2 vec2::operator+(vec2& b)
{
	return vec2(x + b.x, y + b.y);
}

vec2& vec2::operator+=(vec2& b)
{
	x += b.x;
	y += b.y;
	return *this;
}

vec2 vec2::operator-(vec2& b)
{
	return vec2(x - b.x, y - b.y);
}

vec2& vec2::operator-=(vec2& b)
{
	x -= b.x;
	y -= b.y;
	return *this;
}

float vec2::operator*(vec2& b)
{
	return x * b.x + y * b.y;
}

vec2 vec2::operator*(float b)
{
	return vec2(x * b, y * b);
}

vec2& vec2::operator*=(float b)
{
	x *= b;
	y *= b;
	return *this;
}

vec2 vec2::normalize()
{
	float fac = 1 / sqrtf(x * x + y * y);
	return vec2(x * fac, y * fac);
}

vec2 operator*(float a, vec2& b)
{
	return vec2(a * b.x, a * b.y);
}

vec3::vec3()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

vec3::vec3(float p1, float p2, float p3)
{
	x = p1;
	y = p2;
	z = p3;
}

vec3 vec3::operator+(vec3& b)
{
	return vec3(x + b.x, y + b.y, z + b.z);
}

vec3& vec3::operator+=(vec3& b)
{
	x += b.x;
	y += b.y;
	z += b.z;
	return *this;
}

vec3 vec3::operator-(vec3& b)
{
	return vec3(x - b.x, y - b.y, z - b.z);
}

vec3& vec3::operator-=(vec3& b)
{
	x -= b.x;
	y -= b.y;
	z -= b.z;
	return *this;
}

float vec3::operator*(vec3& b)
{
	return x * b.x + y * b.y + z * b.z;
}

vec3 vec3::operator*(float b)
{
	return vec3(x * b, y * b, z * b);
}

vec3& vec3::operator*=(float b)
{
	x *= b;
	y *= b;
	z *= b;
	return *this;
}

vec3 vec3::cross(vec3& b)
{
	return vec3(y * b.z - z * b.y, z * b.x - x * b.z, x * b.y - y * b.x);
}

vec3 vec3::normalize()
{
	float fac = 1 / sqrtf(x * x + y * y + z * z);
	return vec3(x * fac, y * fac, z * fac);
}

vec3 operator*(float a, vec3& b)
{
	return vec3(a * b.x, a * b.y, a * b.z);
}

vec4::vec4()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
	w = 0.0f;
}

vec4::vec4(float p1, float p2, float p3, float p4)
{
	x = p1;
	y = p2;
	z = p3;
	w = p4;
}

vec4 vec4::operator+(vec4& b)
{
	return vec4(x + b.x, y + b.y, z + b.z, w);
}

vec4& vec4::operator+=(vec4& b)
{
	x += b.x;
	y += b.y;
	z += b.z;
	w += b.w;
	return *this;
}

vec4 vec4::operator-(vec4& b)
{
	return vec4(x - b.x, y - b.y, z - b.z, w - b.w);
}

vec4& vec4::operator-=(vec4& b)
{
	x -= b.x;
	y -= b.y;
	z -= b.z;
	w -= b.w;
	return *this;
}

float vec4::operator*(vec4& b)
{
	return x * b.x + y * b.y + z * b.z + w * b.w;
}

vec4 vec4::operator*(float b)
{
	return vec4(x * b, y * b, z * b, w * b);
}

vec4& vec4::operator*=(float b)
{
	x *= b;
	y *= b;
	z *= b;
	w *= b;
	return *this;
}

vec4 vec4::normalize()
{
	float fac = 1 / sqrtf(x * x + y * y + z * z + w * w);
	return vec4(x * fac, y * fac, z * fac, w * fac);
}

vec4 operator*(float a, vec4& b)
{
	return vec4(a * b.x, a * b.y, a * b.z, a * b.w);
}
