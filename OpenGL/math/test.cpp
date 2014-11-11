#include <cstdio>
#include <xmmintrin.h>
#include "math.h"

__m128 vec_add(vec4 a, vec4 b)
{
	__m128 A, B, C;
	A = _mm_set_ps(a.x, a.y, a.z, a.w);
	B = _mm_set_ps(b.x, b.y, b.z, b.w);
	C = _mm_add_ps(A, B);
	return C;
}

int main()
{
	vec4 a = vec4(3.0f, 1.0f, 1.0f, 1.0f);
	vec4 b = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	vec4 c;
#if 0
	for (int i = 0; i < 9999999; i++)
		c = a + b;
	printf("%f %f %f\n", c.x, c.y, c.z);
#endif

	__m128 mc;
	for (int i = 0; i < 9999999; i++)
		mc = vec_add(a, b);	
	printf("%f %f %f", mc[0], mc[1], mc[2]);

	/*
	float a[4] = {2.0f, 0.0f, 0.0f, 1.0f};
	float b[4] = {1.0f, 2.0f, 2.0f, 3.0f};
	mat2 ma = mat2(a);
	mat2 mb = mat2(b);
	mat2 c = ma * mb;
	for (int i = 0; i < 4; i++)
		printf("%f\n", c.data[i]);
	*/

	return 0;
}
