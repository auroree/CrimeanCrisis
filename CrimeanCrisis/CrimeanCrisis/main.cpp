#include "Glowny_kontroler.h"
#include "Renderer.h"

int main(int argc, char const *argv[])
{
	Renderer *rend = new Renderer();		// Renderer test
	std::vector< glm::vec3 > vertices;
	std::vector< glm::vec2 > uvs;
	std::vector< glm::vec3 > normals;
	//rend->createWindow();
	rend->loadOBJ("models/t1.obj", vertices, uvs, normals);

	//glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);
	Glowny_kontroler kontroler;
	kontroler.Start();		//tu jest główna pętla gry
	return 0;
}