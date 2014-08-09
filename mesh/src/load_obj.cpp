#include <vector>
#include <cstring>
#include "../../math/math.h"

using namespace std;

typedef float vec3f[3];
typedef float vec2f[2];
typedef int vec3i[3];

int load_obj(const char* path)
{
	vector<vec3f> vert, norm;
	vector<vec2f> uv;
	vector<vec3i> vert_index, uv_index, norm_index;
	
	FILE* file = fopen(path, "r");
	if (file == NULL)
	{
		printf("file open error!\n");
		return -1;
	}

	while (1)
	{
		/*
		char lineHead[128];
		int res = fscanf(file, "%s", lineHead);
		if (res == EOF)
			break;
		if (strcmp(lineHead, "v") == 0)
		{
			vec3f a_vert;
			fscanf(file, "%f %f %f\n", &a_vert[0], &a_vert[1], &a_vert[2]);
			vert.push_back(a_vert);
		}
		else if (strcmp(lineHead, "vt") == 0)
		{
			vec2f a_uv;
			fscanf(file, "%f %f\n", &a_uv[0], &a_uv[1]);
			uv.push_back(a_uv);
		}
		else if (strcmp(lineHead, "f") == 0)
		{
		*/
	}
