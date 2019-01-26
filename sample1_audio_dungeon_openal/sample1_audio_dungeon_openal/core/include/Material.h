#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>

class Material {
public:
	glm::vec3 ambient;
	glm::vec3 diffuse;
	glm::vec3 specular;
	float shininess;

	Material(glm::vec3 ambient = glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3 diffuse = glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3 specular = glm::vec3(1.0f, 1.0f, 1.0f),
		float shininess = 32.0f);
	virtual ~Material();
};