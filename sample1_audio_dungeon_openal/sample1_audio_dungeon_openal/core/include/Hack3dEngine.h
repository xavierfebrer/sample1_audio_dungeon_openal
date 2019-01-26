#pragma once

#include "Util.h"
#include "Input.h"
#include "Audio.h"
#include "Graphics.h"
#include "Assets.h"

enum class Hack3dEngineReadiness {
	NOT_READY,
	READY,
	ERROR_INPUT,
	ERROR_AUDIO,
	ERROR_GRAPHICS,
	ERROR_ASSETS,
	ERROR_GENERIC
};

class Hack3dEngine {
public:
	static Hack3dEngine* get();
	static void destroy();

	std::shared_ptr<Input> input;
	std::shared_ptr<Audio> audio;
	std::shared_ptr<Graphics> graphics;
	std::shared_ptr<Assets> assets;

	Hack3dEngine();
	virtual ~Hack3dEngine();

	virtual bool init();
	virtual bool isInitialized();
	virtual Hack3dEngineReadiness isReady();
	virtual void resume();
	virtual void startUpdate(double deltaTime);
	virtual void endUpdate(double deltaTime);
	virtual void pause();

	virtual double getTime();
	virtual bool hasRequestExit();
protected:
	static Hack3dEngine * instance;

	virtual double getCurrentTime();
private:
	bool initialized;
	bool requestExit;
	double initTime;
};
