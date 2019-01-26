#include "../../include/Hack3dEngine.h"
#include "../../include/GLFWInput.h"
#include "../../include/OpenALAudio.h"
#include "../../include/GLFWGraphics.h"

Hack3dEngine* Hack3dEngine::instance = nullptr;

Hack3dEngine * Hack3dEngine::get() {
	if (instance == nullptr) {
		instance = new Hack3dEngine();
	}
	return instance;
}

void Hack3dEngine::destroy() {
	if (instance != nullptr) {
		instance->input.reset();
		instance->audio.reset();
		instance->graphics.reset();
		instance->assets.reset();
		delete instance;
	}
}

Hack3dEngine::Hack3dEngine()
	: initialized(false), requestExit(false), initTime(getCurrentTime()) {
}

Hack3dEngine::~Hack3dEngine() {
}

bool Hack3dEngine::init() {
	if (!isInitialized()) {
		initialized = true;
		input.reset(new GLFWInput());
		audio.reset(new OpenALAudio());
		graphics.reset(new GLFWGraphics());
		assets.reset(new Assets());
		input->init();
		audio->init();
		graphics->init();
		assets->init();
	}
	return initialized;
}

bool Hack3dEngine::isInitialized() {
	return initialized;
}

Hack3dEngineReadiness Hack3dEngine::isReady() {
	BaseComponentReadiness inputReady = input->isReady();
	BaseComponentReadiness audioReady = audio->isReady();
	BaseComponentReadiness graphicsReady = graphics->isReady();
	BaseComponentReadiness assetsReady = assets->isReady();
	if (inputReady == BaseComponentReadiness::ERROR_GENERIC) {
		return Hack3dEngineReadiness::ERROR_INPUT;
	}
	if (audioReady == BaseComponentReadiness::ERROR_GENERIC) {
		return Hack3dEngineReadiness::ERROR_AUDIO;
	}
	if (graphicsReady == BaseComponentReadiness::ERROR_GENERIC) {
		return Hack3dEngineReadiness::ERROR_GRAPHICS;
	}
	if (assetsReady == BaseComponentReadiness::ERROR_GENERIC) {
		return Hack3dEngineReadiness::ERROR_ASSETS;
	}
	return (isInitialized()
		&& inputReady == BaseComponentReadiness::READY ? true : false
		&& audioReady == BaseComponentReadiness::READY ? true : false
		&& graphicsReady == BaseComponentReadiness::READY ? true : false
		&& assetsReady == BaseComponentReadiness::READY ? true : false)
		? Hack3dEngineReadiness::READY : Hack3dEngineReadiness::NOT_READY;
}

void Hack3dEngine::resume() {
}

void Hack3dEngine::startUpdate(double deltaTime) {
	input->startUpdate(deltaTime);
	audio->startUpdate(deltaTime);
	graphics->startUpdate(deltaTime);
	assets->startUpdate(deltaTime);
	requestExit = input->hasRequestExit() || audio->hasRequestExit() || graphics->hasRequestExit() || assets->hasRequestExit();
}

void Hack3dEngine::endUpdate(double deltaTime) {
	input->endUpdate(deltaTime);
	audio->endUpdate(deltaTime);
	graphics->endUpdate(deltaTime);
	assets->endUpdate(deltaTime);
	requestExit = input->hasRequestExit() || audio->hasRequestExit() || graphics->hasRequestExit() || assets->hasRequestExit();
}

void Hack3dEngine::pause() {
}

double Hack3dEngine::getCurrentTime() {
	return glfwGetTime();
}

double Hack3dEngine::getTime() {
	return getCurrentTime() - initTime;
}

bool Hack3dEngine::hasRequestExit() {
	return requestExit;
}
