#include "..\..\..\include\SpotLight.h"

SpotLight::SpotLight(glm::vec3 position, glm::vec3  direction, float cutOff, float outerCutOff,
	glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular)
	: Light(ambient, diffuse, specular), position(position), direction(direction), cutOff(cutOff), outerCutOff(outerCutOff) {
}

SpotLight::~SpotLight() {
}
