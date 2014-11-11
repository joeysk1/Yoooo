#include "vector.h"
#include "matrix.h"

#ifndef __FUNCS_H
#define __FUNCS_H

mat4 get_view_mat(vec4 x, vec4 y, vec4 z, vec4 w);

mat4 get_proj_mat(float near, float far, float fov, float ratio);

mat4 translate(float x, float y, float z);

#endif
