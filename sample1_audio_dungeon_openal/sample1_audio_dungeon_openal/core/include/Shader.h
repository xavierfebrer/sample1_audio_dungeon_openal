#pragma once

#include <glad/glad.h>

#include "Util.h"

class Shader {
public:
	Shader(const std::string & completeShaderPath);
	virtual ~Shader();

	virtual bool init() = 0;
	virtual bool isInit();
	virtual void deleteShader();
	virtual GLuint getShader();
protected:
	std::string completeShaderPath;
	bool initialized;
	GLuint shader;

	std::string readShaderSource();
	bool compileShader(const std::string & shaderSource, const GLenum & shaderType);
};