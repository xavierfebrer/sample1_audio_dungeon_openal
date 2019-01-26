#pragma once

#include "Util.h"

#include "BaseComponent.h"
#include "TextureRegion2D.h"
#include "MyColor.h"

class Graphics : public BaseComponent<> {
public:
	Graphics();
	virtual ~Graphics() override;

	virtual BaseComponentReadiness isReady() override;

	virtual bool initWindow(int width, int height, const std::string & title, int windowPosLeftX = 0, int windowPosUpY = 0) = 0;

	virtual void startRender(double deltaTime) = 0;
	virtual void clearScreen(float a, float r, float g, float b) = 0;
	virtual void clearScreen(const MyColor & color) = 0;
	virtual void render(const TextureRegion2D& textureRegion2D, double x, double y, double w, double h, double rotationDegrees, double alpha) = 0;
	virtual void endRender(double deltaTime) = 0;
	virtual Vec2<int> getWindowSize() = 0;
};

