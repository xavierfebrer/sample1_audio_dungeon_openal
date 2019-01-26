#include "..\..\..\include\Shader.h"

Shader::Shader(const std::string & completeShaderPath) : completeShaderPath(completeShaderPath), initialized(false) {
}

Shader::~Shader() {
}

bool Shader::isInit() {
	return initialized;
}

void Shader::deleteShader() {
	glDeleteShader(shader);
}

GLuint Shader::getShader() {
	return shader;
}

std::string Shader::readShaderSource() {
	std::string result;
	Util::loadFile(completeShaderPath, result);
	return result;
}

bool Shader::compileShader(const std::string & shaderSource, const GLenum & shaderType) {
	shader = glCreateShader(shaderType);

	const char *shaderSourceCStr = shaderSource.c_str();
	glShaderSource(shader, 1, &shaderSourceCStr, NULL);
	glCompileShader(shader);
	GLint compilationOK = GL_FALSE;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &compilationOK);
	if (compilationOK != GL_TRUE) {
		GLint logLength;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLength);
		std::vector<char> logContainer(logLength);
		glGetShaderInfoLog(shader, logLength, NULL, logContainer.data());
		std::string information(begin(logContainer), end(logContainer));
		std::cerr << "*** Compilation of shaderType (GLenum:" << shaderType << ") path:" << completeShaderPath << ", information" << information << "shader source:" << shaderSource << std::endl;
	}
	return true;
}
