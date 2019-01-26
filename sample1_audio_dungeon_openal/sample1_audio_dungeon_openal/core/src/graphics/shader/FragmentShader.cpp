#include "..\..\..\include\FragmentShader.h"

FragmentShader::FragmentShader(const std::string & completeShaderPath) : Shader(completeShaderPath) {
}

FragmentShader::~FragmentShader() {
}

bool FragmentShader::init() {
	if (!initialized && compileShader(readShaderSource(), GL_FRAGMENT_SHADER)) {
		initialized = true;
	}
	return initialized;
}
