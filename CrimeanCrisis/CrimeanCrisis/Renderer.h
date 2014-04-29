#pragma once

#define _CRT_SECURE_NO_WARNINGS
//#define GLEW_STATIC

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <vector>
#include "lib/GL/glew.h"
#include "lib/GLFW/glfw3.h"
#include "lib/GL/glut.h"
#include "lib/glm/glm.hpp"
#include "lib/glm/gtc/matrix_transform.hpp"


//#pragma comment(lib, "glew32.lib")
//#pragma comment(lib, "opengl32.lib")

class Renderer
{
public:
	Renderer();
	~Renderer();

	bool createWindow();
	void updateWindow();

private:
	GLFWwindow *window;
};

