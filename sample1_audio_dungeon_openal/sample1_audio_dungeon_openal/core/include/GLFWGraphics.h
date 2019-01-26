#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Graphics.h"

class GLFWGraphics : public Graphics {
public:
	std::shared_ptr<GLFWwindow> window;

	GLFWGraphics();
	virtual ~GLFWGraphics() override;

	virtual bool init() override;
	virtual BaseComponentReadiness isReady() override;
	virtual bool initWindow(int width, int height, const std::string & title, int windowPosLeftX = 0, int windowPosUpY = 0) override;
	virtual void startRender(double deltaTime) override;
	virtual void clearScreen(float r, float g, float b, float a) override;
	virtual void clearScreen(const MyColor & color) override;
	virtual void render(const TextureRegion2D& textureRegion2D, double x, double y, double w, double h, double rotationDegrees, double alpha) override;
	virtual void endRender(double deltaTime) override;
	virtual bool hasRequestExit() override;
	virtual Vec2<int> getWindowSize() override;
private:
	bool initGLAD();
};
