#pragma once

#include "Shader.h"

class FragmentShader : public Shader {
public:
	FragmentShader(const std::string & completeShaderPath);
	virtual ~FragmentShader() override;

	virtual bool init() override;
};