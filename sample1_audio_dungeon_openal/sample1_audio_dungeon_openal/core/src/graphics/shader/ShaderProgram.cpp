#include "..\..\..\include\ShaderProgram.h"

ShaderProgram::ShaderProgram(const std::shared_ptr<VertexShader> & vertexShader, const std::shared_ptr<FragmentShader> & fragmentShader):
	vertexShader(vertexShader), fragmentShader(fragmentShader), initialized(false) {
}

ShaderProgram::~ShaderProgram() {
	glDeleteProgram(shaderProgram);
}

bool ShaderProgram::init() {
	if (!initialized
		&& (vertexShader->isInit() || (!vertexShader->isInit() && vertexShader->init()))
		&& (fragmentShader->isInit() || (!fragmentShader->isInit() && fragmentShader->init()))) {

		shaderProgram = glCreateProgram();
		glAttachShader(shaderProgram, vertexShader->getShader());
		glAttachShader(shaderProgram, fragmentShader->getShader());
		glLinkProgram(shaderProgram);
		GLint linkOK = GL_FALSE;
		glGetProgramiv(shaderProgram, GL_LINK_STATUS, &linkOK);
		if (linkOK != GL_TRUE) {
			GLint logLength;
			glGetProgramiv(shaderProgram, GL_INFO_LOG_LENGTH, &logLength);
			std::vector<char> logContainer(logLength);
			glGetProgramInfoLog(shaderProgram, logLength, NULL, logContainer.data());
			std::string information(begin(logContainer), end(logContainer));
			std::cerr << "*** Link program: " << information << std::endl;
		}
		vertexShader->deleteShader();
		fragmentShader->deleteShader();
		initialized = true;
	}
	return initialized;
}

bool ShaderProgram::isInit() {
	return initialized;
}

void ShaderProgram::use() {
	glUseProgram(shaderProgram);
}

unsigned int ShaderProgram::getProgram() {
	return shaderProgram;
}

void ShaderProgram::setBool(const std::string &name, bool value) const {         
	glUniform1i(glGetUniformLocation(shaderProgram, name.c_str()), (int)value);
}

void ShaderProgram::setInt(const std::string &name, int value) const { 
	glUniform1i(glGetUniformLocation(shaderProgram, name.c_str()), value);
}

void ShaderProgram::setUInt(const std::string &name, unsigned int value) const { 
	glUniform1ui(glGetUniformLocation(shaderProgram, name.c_str()), value);
}

void ShaderProgram::setFloat(const std::string &name, float value) const { 
	glUniform1f(glGetUniformLocation(shaderProgram, name.c_str()), value);
}

void ShaderProgram::setVec2(const std::string &name, const glm::vec2 &value) const {
	glUniform2fv(glGetUniformLocation(shaderProgram, name.c_str()), 1, &value[0]);
}

void ShaderProgram::setVec2(const std::string &name, float x, float y) const {
	glUniform2f(glGetUniformLocation(shaderProgram, name.c_str()), x, y);
}

void ShaderProgram::setVec3(const std::string &name, const glm::vec3 &value) const {
	glUniform3fv(glGetUniformLocation(shaderProgram, name.c_str()), 1, &value[0]);
}

void ShaderProgram::setVec3(const std::string &name, float x, float y, float z) const {
	glUniform3f(glGetUniformLocation(shaderProgram, name.c_str()), x, y, z);
}

void ShaderProgram::setVec4(const std::string &name, const glm::vec4 &value) const {
	glUniform4fv(glGetUniformLocation(shaderProgram, name.c_str()), 1, &value[0]);
}

void ShaderProgram::setVec4(const std::string &name, float x, float y, float z, float w) const {
	glUniform4f(glGetUniformLocation(shaderProgram, name.c_str()), x, y, z, w);
}

void ShaderProgram::setMat2(const std::string &name, const glm::mat2 &mat) const {
	glUniformMatrix2fv(glGetUniformLocation(shaderProgram, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

void ShaderProgram::setMat3(const std::string &name, const glm::mat3 &mat) const {
	glUniformMatrix3fv(glGetUniformLocation(shaderProgram, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

void ShaderProgram::setMat4(const std::string &name, const glm::mat4 &mat) const {
	glUniformMatrix4fv(glGetUniformLocation(shaderProgram, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}
