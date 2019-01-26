#pragma once

#include <glm/glm.hpp>
#include "Light.h"

class SpotLight : public Light {
public:
	glm::vec3  position;
	glm::vec3  direction;
	float cutOff;		// radians, in, starts fade outside, complete light inside
	float outerCutOff;	// radians, out, outside no light, inside and between cutOff and outerCutOff gradient fade

	SpotLight(glm::vec3 position,
		glm::vec3  direction,
		float cutOff,
		float outerCutOff,
		glm::vec3 ambient = glm::vec3(1.0f),
		glm::vec3 diffuse = glm::vec3(1.0f),
		glm::vec3 specular = glm::vec3(1.0f));
	virtual ~SpotLight();
};