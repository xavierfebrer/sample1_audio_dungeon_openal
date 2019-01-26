#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Input.h"

class GLFWInput : public Input {
public:
	GLFWInput();
	virtual ~GLFWInput() override;

	virtual bool init() override;
	virtual void mousePosCallback(GLFWwindow * window, double xpos, double ypos);
	virtual void mouseButtonCallback(GLFWwindow * window, int button, int action, int mods);
	virtual void keyCallback(GLFWwindow * window, int key, int scancode, int action, int mods);
	virtual void setCallbacks();
	virtual BaseComponentReadiness isReady() override;
	virtual void startUpdate(double deltaTime) override;
	virtual void endUpdate(double deltaTime) override;
private:
	void processInput(GLFWwindow *window);
};
