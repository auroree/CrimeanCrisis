#include "Renderer.h"

using namespace glm;

Renderer::Renderer() : window(NULL)
{
}


Renderer::~Renderer()
{
}


bool Renderer::createWindow() {
	//glEnable(GL_TEXTURE_2D);
	if (!glfwInit())
	{
		printf("Failed to initialize GLFW!\n");
		return false;
	}

	glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
	//glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
	//glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //We don't want the old OpenGL

	// Open a window and create its OpenGL context
	window; // (In the accompanying source code, this variable is global)
	window = glfwCreateWindow(800, 600, "CrimeanCrisis	", NULL, NULL);
	if (window == NULL) 
	{
		fprintf(stderr, "Failed to open GLFW window!\n");
		glfwTerminate();
		return false;
	}
	glfwMakeContextCurrent(window);

	//glewExperimental = GL_TRUE; // Needed in core profile (!)
	if (glewInit() != GLEW_OK) 
	{
		fprintf(stderr, "Failed to initialize GLEW!\n");
		return false;
	}

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	//do
	//{
	//	// Swap buffers
	//	glfwSwapBuffers(window);
	//	glfwPollEvents();

	//} // Check if the ESC key was pressed or the window was closed
	//while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);
	return true;
}


void Renderer::updateWindow()
{
	//jak sie pewnie Pawe³ domyœlasz - tutaj bêdzie aktualizacja widoku wszystkich obiektów.
	//na razie tylko zamieniam bufor
		// Swap buffers
	glfwSwapBuffers(window);
}
