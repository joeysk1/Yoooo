#include "../math.h"

const float PI = 3.14159265;

mat4 get_view_mat(vec4 x, vec4 y, vec4 z, vec4 w)
{
	vec4 trans = vec4(-w.x*x.x - w.y*x.y - w.z*x.z, -w.x*y.x - w.y*y.y - w.z* y.z, -w.x*z.x - w.y*z.y - w.z*z.z, 1.0f);
	mat4 corr = mat4(x, y, z, trans);
	return corr;
}

mat4 get_proj_mat(float near, float far, float fov, float ratio)
{
	float hor = tan(fov / 360.0f * PI) * near;
	float ver = hor / ratio;
	mat4 proj;
	proj.data[0] = near / hor;
	proj.data[5] = near / ver;
	proj.data[10] = -(far + near) / (far - near);
	proj.data[11] = -2 * far * near / (far - near);
	proj.data[14] = -1.0f;
	return proj;
}

mat4 translate(float x, float y, float z)
{
	mat4 trans;
	trans.data[0] = 1.0f;
	trans.data[5] = 1.0f;
	trans.data[10] = 1.0f;
	trans.data[12] = x;
	trans.data[13] = y;
	trans.data[14] = z;
	trans.data[15] = 1.0f;
	return trans;
}
