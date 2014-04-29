#pragma once

#define _CRT_SECURE_NO_WARNINGS
//#define GLEW_STATIC

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include "lib/GL/glew.h"
#include "lib/GLFW/glfw3.h"
#include "lib/glm/glm.hpp"
#include "lib/glm/gtc/matrix_transform.hpp"
#include <vector>

using namespace glm;
using namespace std;

class GraphicObject
{
public:
	GraphicObject();
	virtual ~GraphicObject();

	virtual bool loadOBJ(const char * path,
		vector < glm::vec3 > &out_vertices,
		vector < glm::vec2 > &out_uvs,
		vector < glm::vec3 > &out_normals);

	virtual void Update() {};

private:
	vector< unsigned int > vertexIndices, uvIndices, normalIndices;
	vector< glm::vec3 > temp_vertices;
	vector< glm::vec2 > temp_uvs;
	vector< glm::vec3 > temp_normals;
};

