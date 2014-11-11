#include <GL/glew.h>
#include <string>

class shader
{
private:
	GLuint id;
	GLuint type;
public:
	shader(GLuint atype);
	~shader();

	GLuint get_id();
	GLuint get_type();
	bool open(const char* filename);
};

class program
{
private:
	GLuint id;
	bool status;
public:
	program();
	~program();

	GLuint get_id();
	bool attach(int count, ...);
	bool use();
};
