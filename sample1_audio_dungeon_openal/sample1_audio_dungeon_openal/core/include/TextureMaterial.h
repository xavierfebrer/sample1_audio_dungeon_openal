#pragma once

#include "Material.h"

class TextureMaterial : public Material {
public:
	GLint diffuse;
	GLint specular;
	float shininess;

	TextureMaterial(GLint diffuse,
		GLint specular,
		float shininess = 32.0f);
	virtual ~TextureMaterial();
};