#include "../include/verts.h"

//constructors and destructor
verts::verts()
{
	data = NULL;
	count = 0;
}

verts::verts(int c, float* source)
{
	data = new float[c];
	for (int i = 0; i < c; i++)
		data[i] = source[i];
	count = c;
}

verts::~verts()
{
	if (data != NULL)
		delete[] data;
}

//data operation method
void verts::set_data(int c, float* source)
{
	if (data != NULL)
		delete[] data;
	data = new float[c];
	for (int i = 0; i < c; i++)
		data[i] = source[i];
	count = c;
}

void verts::free_data()
{
	if (data != NULL)
	{
		delete[] data;
		data = NULL;
		count = 0;
	}
}

//geometry generate method
void verts::verts_cube()
{
	free_data();
	data = new float[6 * 4 * 3];

	//up face
	data[ 0] = -0.5f, data[ 1] =  0.5f, data[ 2] =  0.5f; //x, y, z
	data[ 3] =  0.5f, data[ 4] =  0.5f, data[ 5] =  0.5f;
	data[ 6] =  0.5f, data[ 7] =  0.5f, data[ 8] = -0.5f;
	data[ 9] = -0.5f, data[10] =  0.5f, data[11] = -0.5f;

	//front face
	data[12] = -0.5f, data[13] =  0.5f, data[14] =  0.5f;
	data[15] = -0.5f, data[16] = -0.5f, data[17] =  0.5f;
	data[18] =  0.5f, data[19] = -0.5f, data[20] =  0.5f;
	data[21] =  0.5f, data[22] =  0.5f, data[23] =  0.5f;

	//bottom face
	data[24] = -0.5f, data[25] = -0.5f, data[26] =  0.5f;
	data[27] = -0.5f, data[28] = -0.5f, data[29] = -0.5f;
	data[30] =  0.5f, data[31] = -0.5f, data[32] = -0.5f;
	data[33] =  0.5f, data[34] = -0.5f, data[35] =  0.5f;

	//back face
	data[36] = -0.5f, data[37] =  0.5f, data[38] = -0.5f;
	data[39] =  0.5f, data[40] =  0.5f, data[41] = -0.5f;
	data[42] =  0.5f, data[43] = -0.5f, data[44] = -0.5f;
	data[45] = -0.5f, data[46] = -0.5f, data[47] = -0.5f;

	//left face
	data[48] = -0.5f, data[49] =  0.5f, data[50] =  0.5f;
	data[51] = -0.5f, data[52] =  0.5f, data[53] = -0.5f;
	data[54] = -0.5f, data[55] = -0.5f, data[56] = -0.5f;
	data[57] = -0.5f, data[58] = -0.5f, data[59] =  0.5f;

	//right face
	data[60] =  0.5f, data[61] =  0.5f, data[62] =  0.5f;
	data[63] =  0.5f, data[64] = -0.5f, data[65] =  0.5f;
	data[66] =  0.5f, data[67] = -0.5f, data[68] = -0.5f;
	data[69] =  0.5f, data[70] =  0.5f, data[71] = -0.5f;
	 
	count = 72;
}
