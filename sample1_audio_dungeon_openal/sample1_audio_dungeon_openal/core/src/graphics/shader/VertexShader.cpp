#include "..\..\..\include\VertexShader.h"

VertexShader::VertexShader(const std::string & completeShaderPath) : Shader(completeShaderPath) {
}

VertexShader::~VertexShader() {
}

bool VertexShader::init() {
	if (!initialized && compileShader(readShaderSource(), GL_VERTEX_SHADER)) {
		initialized = true;
	}
	return initialized;
}
