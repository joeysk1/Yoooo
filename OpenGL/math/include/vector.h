class vec2
{
public:
	float x;
	float y;

	vec2();
	vec2(float p1, float p2);

	vec2 	operator+(vec2& b);
	vec2& 	operator+=(vec2& b);
	vec2 	operator-(vec2& b);
	vec2&   operator-=(vec2& b);
	float	operator*(vec2& b);
	vec2 	operator*(float b);
	vec2&	operator*=(float b);

	vec2	normalize();

	friend vec2 operator*(float a, vec2& b);
};

class vec3
{
public:
	float x;
	float y;
	float z;

	vec3();
	vec3(float p1, float p2, float p3);

	vec3	operator+(vec3& b);
	vec3&	operator+=(vec3& b);
	vec3	operator-(vec3& b);
	vec3&	operator-=(vec3& b);
	float	operator*(vec3& b);
	vec3	operator*(float b);
	vec3&	operator*=(float b);

	vec3	cross(vec3& b);
	vec3	normalize();

	friend vec3 operator*(float a, vec3& b);
};

class vec4
{
public:
	float x;
	float y;
	float z;
	float w;

	vec4();
	vec4(float p1, float p2, float p3, float p4);

	vec4 	operator+(vec4& b);
	vec4& 	operator+=(vec4& b);
	vec4	operator-(vec4& b);
	vec4&	operator-=(vec4& b);
	float	operator*(vec4& b);
	vec4	operator*(float b);
	vec4&	operator*=(float b);

	vec4	normalize();
	
	friend vec4	operator*(float a, vec4& b);
};
