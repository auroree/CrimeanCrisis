#pragma once

#define _CRT_SECURE_NO_WARNINGS
//#define GLEW_STATIC

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>

//#pragma comment(lib, "glew32.lib")
//#pragma comment(lib, "opengl32.lib")

using namespace std;

class Renderer
{
private:
	vector< unsigned int > vertexIndices, uvIndices, normalIndices;
	vector< glm::vec3 > temp_vertices;
	vector< glm::vec2 > temp_uvs;
	vector< glm::vec3 > temp_normals;

public:
	Renderer();
	~Renderer();

	bool loadOBJ(const char * path,
		vector < glm::vec3 > &out_vertices,
		vector < glm::vec2 > &out_uvs,
		vector < glm::vec3 > &out_normals);

	bool createWindow();
};

