#pragma once

#include <glm/glm.hpp>
#include "Light.h"

class PointLight : public Light {
public:
	glm::vec3 position;
	// attenuation
	float constant;
	float linear;
	float quadratic;

	PointLight(glm::vec3 position,
		float constant = 1.0f,
		float linear = 0.0f,
		float quadratic = 0.0f,
		glm::vec3 ambient = glm::vec3(1.0f),
		glm::vec3 diffuse = glm::vec3(1.0f),
		glm::vec3 specular = glm::vec3(1.0f));
	virtual ~PointLight();
};