#include <cmath>
#include <cstring>
#include "../include/matrix.h"

 //column major

mat2::mat2()
{
	memset(data, 0, 4 * anum);
}

mat2::mat2(float* source)
{
	memcpy(data, source, 4 * anum);
}

mat2 mat2::operator+(mat2& b)
{
	int i;
	mat2 tmp;
	for (i = 0; i < anum; i++)
		tmp.data[i] = data[i] + b.data[i];
	return tmp;
}

mat2& mat2::operator+=(mat2& b)
{
	int i;
	for (i = 0; i < anum; i++)
		data[i] += b.data[i];
	return *this;
}

mat2 mat2::operator-(mat2& b)
{
	int i;
	mat2 tmp;
	for (i = 0; i < anum; i++)
		tmp.data[i] = data[i] - b.data[i];
	return tmp;
}

mat2& mat2::operator-=(mat2& b)
{
	int i;
	for (i = 0; i < anum; i++)
		data[i] -= b.data[i];
	return *this;
}

mat2 mat2::operator*(mat2& b)
{
	/*
	int i, j;
	mat2 tmp;
	for (i = 0; i < anum; i++)
	{
		int row = i / num;
		int col = i % num;
		float value = 0.0f;
		for (j = 0; j < num; j++)
		{
			value += data[row + j * num] * b.data[col * num + j];
		}
		tmp.data[i] = value;
	}
	*/

	mat2 tmp;

	tmp.data[0] = data[0] * b.data[0] + data[2] * b.data[1];
	tmp.data[1] = data[1] * b.data[0] + data[3] * b.data[1];

	tmp.data[2] = data[0] * b.data[2] + data[2] * b.data[3];
	tmp.data[3] = data[1] * b.data[2] + data[3] * b.data[3];

	return tmp;
}

mat2& mat2::operator*=(mat2& b)
{
	mat2 tmp = *this * b;
	*this = tmp;
	return *this;
}

mat2 mat2::operator*(float b)
{
	int i;
	mat2 tmp;
	for (i = 0; i < anum; i++)
		tmp.data[i] = data[i] * b;
	return tmp;
}

mat2& mat2::operator*=(float b)
{
	int i;
	for (i = 0; i < anum; i++)
		data[i] *= b;
	return *this;
}

mat2 operator*(float a, mat2 b)
{
	return b * a;
}

mat3::mat3()
{
	memset(data, 0, 4 * anum);
}

mat3::mat3(float* source)
{
	memcpy(data, source, 4 * anum);
}

mat3 mat3::operator+(mat3& b)
{
	int i;
	mat3 tmp;
	for (i = 0; i < anum; i++)
		tmp.data[i] = data[i] + b.data[i];
	return tmp;
}

mat3& mat3::operator+=(mat3& b)
{
	int i;
	for (i = 0; i < anum; i++)
		data[i] += b.data[i];
	return *this;
}

mat3 mat3::operator-(mat3& b)
{
	int i;
	mat3 tmp;
	for (i = 0; i < anum; i++)
		tmp.data[i] = data[i] - b.data[i];
	return tmp;
}

mat3& mat3::operator-=(mat3& b)
{
	int i;
	for (i = 0; i < anum; i++)
		data[i] -= b.data[i];
	return *this;
}

mat3 mat3::operator*(mat3& b)
{
	mat3 tmp;

	tmp.data[0] = data[0] * b.data[0] + data[3] * b.data[1] + data[6] * b.data[2];
	tmp.data[1] = data[1] * b.data[0] + data[4] * b.data[1] + data[7] * b.data[2];
	tmp.data[2] = data[2] * b.data[0] + data[5] * b.data[1] + data[8] * b.data[2];

	tmp.data[3] = data[0] * b.data[3] + data[3] * b.data[4] + data[6] * b.data[7];
	tmp.data[4] = data[1] * b.data[3] + data[4] * b.data[4] + data[7] * b.data[7];
	tmp.data[5] = data[2] * b.data[3] + data[5] * b.data[4] + data[8] * b.data[7];

	tmp.data[6] = data[0] * b.data[6] + data[3] * b.data[7] + data[6] * b.data[8];
	tmp.data[7] = data[1] * b.data[6] + data[4] * b.data[7] + data[7] * b.data[8];
	tmp.data[8] = data[2] * b.data[6] + data[5] * b.data[7] + data[8] * b.data[8];

	return tmp;
}

mat3& mat3::operator*=(mat3& b)
{
	mat3 tmp = *this * b;
	*this = tmp;
	return *this;
}

mat3 mat3::operator*(float b)
{
	int i;
	mat3 tmp;
	for (i = 0; i < anum; i++)
		tmp.data[i] = data[i] * b;
	return tmp;
}

mat3& mat3::operator*=(float b)
{
	int i;
	for (i = 0; i < anum; i++)
		data[i] *= b;
	return *this;
}

mat3 operator*(float a, mat3 b)
{
	return b * a;
}

mat4::mat4()
{
	memset(data, 0, 4 * anum);
}

mat4::mat4(float* source)
{
	memcpy(data, source, 4 * anum);
}

mat4 mat4::operator*(mat4& b)
{
	mat4 tmp;

	tmp.data[0] = data[0] * b.data[0] + data[4] * b.data[1] + data[8] * b.data[2] + data[12] * b.data[3];
	tmp.data[1] = data[1] * b.data[0] + data[5] * b.data[1] + data[9] * b.data[2] + data[13] * b.data[3];
	tmp.data[2] = data[2] * b.data[0] + data[6] * b.data[1] + data[10] * b.data[2] + data[14] * b.data[3];
	tmp.data[3] = data[3] * b.data[0] + data[7] * b.data[1] + data[11] * b.data[2] + data[15] * b.data[3];

	tmp.data[4] = data[0] * b.data[4] + data[4] * b.data[5] + data[8] * b.data[6] + data[12] * b.data[7];
	tmp.data[5] = data[1] * b.data[4] + data[5] * b.data[5] + data[9] * b.data[6] + data[13] * b.data[7];
	tmp.data[6] = data[2] * b.data[4] + data[6] * b.data[5] + data[10] * b.data[6] + data[14] * b.data[7];
	tmp.data[7] = data[3] * b.data[4] + data[7] * b.data[5] + data[11] * b.data[6] + data[15] * b.data[7];

	tmp.data[8] = data[0] * b.data[8] + data[4] * b.data[9] + data[8] * b.data[10] + data[12] * b.data[11];
	tmp.data[9] = data[1] * b.data[8] + data[5] * b.data[9] + data[9] * b.data[10] + data[13] * b.data[11];
	tmp.data[10] = data[2] * b.data[8] + data[6] * b.data[9] + data[10] * b.data[10] + data[14] * b.data[11];
	tmp.data[11] = data[3] * b.data[8] + data[7] * b.data[9] + data[11] * b.data[10] + data[15] * b.data[11];

	tmp.data[12] = data[0] * b.data[12] + data[4] * b.data[13] + data[8] * b.data[14] + data[12] * b.data[15];
	tmp.data[13] = data[1] * b.data[12] + data[5] * b.data[13] + data[9] * b.data[14] + data[13] * b.data[15];
	tmp.data[14] = data[2] * b.data[12] + data[6] * b.data[13] + data[10] * b.data[14] + data[14] * b.data[15];
	tmp.data[15] = data[3] * b.data[12] + data[7] * b.data[13] + data[11] * b.data[14] + data[15] * b.data[15];

	return tmp;
}

mat4& mat4::operator*=(mat4& b)
{
	mat4 tmp = *this * b;
	*this = tmp;
	return *this;
}

mat4 mat4::operator*(float b)
{
	int i;
	mat4 tmp;
	for (i = 0; i < anum; i++)
		tmp.data[i] = data[i] * b;
	return tmp;
}

mat4& mat4::operator*=(float b)
{
	int i;
	for (i = 0; i < anum; i++)
		data[i] *= b;
	return *this;
}

mat4 operator*(float a, mat4 b)
{
	return b * a;
}
