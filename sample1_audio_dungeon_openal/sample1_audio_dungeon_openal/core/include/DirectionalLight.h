#pragma once

#include <glm/glm.hpp>
#include "Light.h"

class DirectionalLight : public Light {
public:
	glm::vec3 direction;

	DirectionalLight(glm::vec3 direction, glm::vec3 ambient = glm::vec3(1.0f),
		glm::vec3 diffuse = glm::vec3(1.0f),
		glm::vec3 specular = glm::vec3(1.0f));
	virtual ~DirectionalLight();
};