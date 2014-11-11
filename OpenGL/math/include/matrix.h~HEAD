#include <cmath>
#include "vector.h"

#ifndef __MATRIX_H
#define __MATRIX_H

class mat2
{
public:
	float data[4];
	const static int num = 2;
	const static int anum = 4;

	mat2();
	mat2(float* source);
	
	mat2	operator+(mat2& b);
	mat2&	operator+=(mat2& b);
	mat2	operator-(mat2& b);
	mat2&	operator-=(mat2& b);
	mat2	operator*(mat2& b);
	mat2&	operator*=(mat2& b);
	mat2	operator*(float b);
	mat2&	operator*=(float b);

	friend mat2 operator*(float a, mat2 b);
};

class mat3
{
public:
	float data[9];
	const static int num = 3;
	const static int anum = 9;

	mat3();
	mat3(float* source);

	mat3	operator+(mat3& b);
	mat3&	operator+=(mat3& b);
	mat3	operator-(mat3& b);
	mat3&	operator-=(mat3& b);
	mat3	operator*(mat3& b);
	mat3&	operator*=(mat3& b);
	mat3	operator*(float b);
	mat3&	operator*=(float b);

	friend mat3 operator*(float a, mat3 b);
};

class mat4
{
public:
	float data[16];
	const static int num = 4;
	const static int anum = 16;

	mat4();
	mat4(float* source);
	mat4(vec4 x, vec4 y, vec4 z, vec4 w);

	//mat4	operator+(mat4& b);
	//mat4&	operator+=(mat4& b);
	//mat4	operator-(mat4& b);
	//mat4&	operator-=(mat4& b);
	mat4	operator*(mat4& b);
	mat4&	operator*=(mat4& b);
	mat4	operator*(float b);
	mat4&	operator*=(float b);

	friend mat4 operator*(float a, mat4 b);
};

#endif
