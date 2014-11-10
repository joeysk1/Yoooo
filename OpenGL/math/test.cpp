#include <cstdio>
#include "math.h"

int main()
{
	//vec3 a = vec3(3.0f, 1.0f, 1.0f);
	//vec3 b = vec3(1.0f, 1.0f, 1.0f);
	//b += a;
	//printf("%f %f %f\n", a.x, a.y, a.z);
	//printf("%f %f %f\n", b.x, b.y, b.z);

	float a[4] = {2.0f, 0.0f, 0.0f, 1.0f};
	float b[4] = {1.0f, 2.0f, 2.0f, 3.0f};
	mat2 ma = mat2(a);
	mat2 mb = mat2(b);
	mat2 c = ma * mb;
	for (int i = 0; i < 4; i++)
		printf("%f\n", c.data[i]);
	return 0;
}
