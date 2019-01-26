#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Util.h"

#include "VertexShader.h"
#include "FragmentShader.h"

class ShaderProgram {
public:
	ShaderProgram(const std::shared_ptr<VertexShader> & vertexShader, const std::shared_ptr<FragmentShader> & fragmentShader);
	virtual ~ShaderProgram();

	virtual bool init();
	virtual bool isInit();
	virtual void use();
	virtual unsigned int getProgram();
	void setBool(const std::string & name, bool value) const;
	void setInt(const std::string & name, int value) const;
	void setUInt(const std::string & name, unsigned int value) const;
	void setFloat(const std::string & name, float value) const;
	void setVec2(const std::string & name, const glm::vec2 & value) const;
	void setVec2(const std::string & name, float x, float y) const;
	void setVec3(const std::string & name, const glm::vec3 & value) const;
	void setVec3(const std::string & name, float x, float y, float z) const;
	void setVec4(const std::string & name, const glm::vec4 & value) const;
	void setVec4(const std::string & name, float x, float y, float z, float w) const;
	void setMat2(const std::string & name, const glm::mat2 & mat) const;
	void setMat3(const std::string & name, const glm::mat3 & mat) const;
	void setMat4(const std::string & name, const glm::mat4 & mat) const;
protected:
	std::shared_ptr<VertexShader> vertexShader;
	std::shared_ptr<FragmentShader> fragmentShader;
	bool initialized;
	unsigned int shaderProgram;
};