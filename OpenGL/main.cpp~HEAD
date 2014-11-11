#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <xmmintrin.h>
#include "shader/shader_manager.h"
#include "mesh/mesh.h"
#include "math/math.h"

float x = 0.0f;
float y = 0.0f;
float z = 0.0f;

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
	else if (key == GLFW_KEY_W && (action == GLFW_PRESS || action == GLFW_REPEAT))
		z += 0.1f;
	else if (key == GLFW_KEY_S && (action == GLFW_PRESS || action == GLFW_REPEAT))
		z -= 0.1f;
	else if (key == GLFW_KEY_A && (action == GLFW_PRESS || action == GLFW_REPEAT))
		x += 0.1f;
	else if (key == GLFW_KEY_D && (action == GLFW_PRESS || action == GLFW_REPEAT))
		x -= 0.1f;
	else if (key == GLFW_KEY_Q && (action == GLFW_PRESS || action == GLFW_REPEAT))
		y -= 0.1f;
	else if (key == GLFW_KEY_E && (action == GLFW_PRESS || action == GLFW_REPEAT))
		y += 0.1f;
}

float view_data[16] = {
	1.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 1.0f
};
/*
float proj_data[16] = {
};
*/

mat4 view_mat = mat4(view_data);
mat4 proj_mat = get_proj_mat(1.0f, 100.0f, 45.0f, 1.0f);
//mat4 trans_mat = translate(x, y, z);

GLuint mvp_id;
//GLuint trans_id;

int main(void)
{
    //__m128 m;
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    
    window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		return -1;
	}
    
    glewExperimental = true; // Needed for core profile
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		return -1;
	}
    
    glfwSetKeyCallback(window, key_callback);
    
    shader vs = shader(GL_VERTEX_SHADER);
    vs.open("./shader/SimpleVertexShader.vertexshader");
    shader fs = shader(GL_FRAGMENT_SHADER);
    fs.open("./shader/SimpleFragmentShader.fragmentshader");
    program pro;
    pro.attach(2, vs.get_id(), fs.get_id());
    //pro.use();

	mvp_id = glGetUniformLocation(pro.get_id(), "mvp");
	//trans_id = glGetUniformLocation(pro.get_id(), "trans");
    
    GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);
    
    static const GLfloat vertex_data[] = {
		-0.5f, -0.5f,  -1.5f,
         0.5f, -0.5f,  -1.5f,
         0.5f,  0.5f,  -1.5f,
        -0.5f,  0.5f,  -1.5f,
		-0.5f, -0.5f,  -1.5f,
		 0.5f,  0.5f,  -1.5f
    };
    
    verts cube = verts();
    cube.verts_cube();
    
	GLuint vertexbuffer;
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_data), vertex_data, GL_STATIC_DRAW);
    //glBufferData(GL_ARRAY_BUFFER, cube.count, cube.data, GL_STATIC_DRAW);

    
    do{
 		//debug print
		//printf("%f %f %f\n", x, y, z);
#if 0
		mat4 tmp = view_mat * proj_mat * trans_mat;
		for (int i = 0; i < 4; i++)
			printf("%f %f %f %f\n", tmp.data[i * 4], tmp.data[i * 4 + 1], tmp.data[i * 4 + 2], tmp.data[i * 4 + 3]);
#endif

		// Clear the screen
		glClear( GL_COLOR_BUFFER_BIT );
        
		// Use our shader
		pro.use();

		// Init Uniforms
		mat4 trans_mat = translate(x, y, z);
		glUniformMatrix4fv(mvp_id, 1, GL_FALSE, (view_mat * proj_mat * trans_mat).data);
        
		// 1rst attribute buffer : vertices
        //glTranslatef(0.0f, 0.0f, -5.0f);
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
		glVertexAttribPointer(
                              0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
                              3,                  // size
                              GL_FLOAT,           // type
                              GL_FALSE,           // normalized?
                              0,                  // stride
                              (void*)0            // array buffer offset
                              );
        
		// Draw the triangle !
		glDrawArrays(GL_TRIANGLES, 0, 6); // 3 indices starting at 0 -> 1 triangle
        
		glDisableVertexAttribArray(0);
        
		// Swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();
        
	} // Check if the ESC key was pressed or the window was closed
	while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
          glfwWindowShouldClose(window) == 0 );
    
    glDeleteBuffers(1, &vertexbuffer);
    glDeleteVertexArrays(1, &VertexArrayID);
    
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
