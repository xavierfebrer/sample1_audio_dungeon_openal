#pragma once

#include <glm/glm.hpp>

#include "Util.h"
#include "Vertex.h"
#include "Texture.h"
#include "ShaderProgram.h"

class Mesh {
public:
	/*  Mesh Data  */
	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;
	std::vector<Texture> textures;
	unsigned int VAO;

	Mesh(const std::vector<Vertex> & vertices, const std::vector<unsigned int> & indices, const std::vector<Texture> & textures);
	virtual ~Mesh();
	void draw(ShaderProgram & shader);
private:
	/*  Render data  */
	unsigned int VBO, EBO;

	void setupMesh();
};