#pragma once

#include "Shader.h"

class VertexShader : public Shader {
public:
	VertexShader(const std::string & completeShaderPath);
	virtual ~VertexShader() override;

	virtual bool init() override;
};