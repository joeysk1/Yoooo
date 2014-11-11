#include <GL/glew.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdarg>
#include "shader_manager.h"

using namespace std;

shader::shader(GLuint atype)
{
	type = atype;
	id = glCreateShader(atype);
	if (id == 0)
		cerr << "shader type error\n" << endl;
}

shader::~shader()
{
	glDeleteShader(id);
}

GLuint shader::get_id()
{
	return id;
}

GLuint shader::get_type()
{
	return type;
}

bool shader::open(const char* filename)
{
	string source = "";
	ifstream input(filename, ifstream::in);
	if (input.is_open())
	{
		string line = "";
		while (getline(input, line))
			source += "\n" + line;
		input.close();
	}
	else
	{
		cerr << "file open error" << endl;
		return false;
	}

	GLint result = GL_FALSE;
	int   infoLength;

	char const* sourcept = source.c_str();
	glShaderSource(id, 1, &sourcept, NULL);
	glCompileShader(id);

	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	glGetShaderiv(id, GL_INFO_LOG_LENGTH, &infoLength);
	if (infoLength > 0)
	{
		char *infoLog = new char[infoLength + 1];
		glGetShaderInfoLog(id, infoLength, NULL, infoLog);
		cerr << infoLog << endl;
		delete [] infoLog;
		return false;
	}
	
	return true;
}

program::program()
{
	id = glCreateProgram();
	status = false;
}

program::~program()
{
	glDeleteProgram(id);
}

GLuint program::get_id()
{
	return id;
}

bool program::attach(int count, ...)
{
	va_list ap;
	va_start(ap, count);
	GLuint a_shader;
	for (int i = 0; i < count; i++)
	{
		a_shader = va_arg(ap, GLuint);
		glAttachShader(id, a_shader);
	}
	va_end(ap);

	glLinkProgram(id);

	GLint result;
	int infoLength;
	glGetProgramiv(id, GL_LINK_STATUS, &result);
	glGetProgramiv(id, GL_INFO_LOG_LENGTH, &infoLength);
	if (infoLength > 0)
	{
		char* infoLog = new char[infoLength + 1];
		glGetProgramInfoLog(id, infoLength, NULL, infoLog);
		cerr << infoLog << endl;
		delete [] infoLog;
		status = false;
		return false;
	}

	status = true;
	return true;
}

bool program::use()
{
	if (status)
	{
		glUseProgram(id);
		return true;
	}
	else
	{
		cerr << "program invalid" << endl;
		return false;
	}
}
