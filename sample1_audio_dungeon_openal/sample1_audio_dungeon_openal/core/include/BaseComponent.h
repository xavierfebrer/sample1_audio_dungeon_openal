#pragma once

enum class BaseComponentReadiness {
	NOT_READY,
	READY,
	ERROR_GENERIC,
};

template<typename R = BaseComponentReadiness>
class BaseComponent {
public:
	BaseComponent();
	virtual ~BaseComponent();

	virtual bool init();
	virtual bool isInitialized();
	virtual R isReady() = 0;
	virtual void resume();
	virtual void startUpdate(double deltaTime);
	virtual void endUpdate(double deltaTime);
	virtual void pause();
	virtual bool hasRequestExit();
protected:
	bool initialized;
	bool requestExit;
};


template<typename R>
BaseComponent<R>::BaseComponent()
	: initialized(false), requestExit(false) {
}

template<typename R>
BaseComponent<R>::~BaseComponent() {
}

template<typename R>
bool BaseComponent<R>::init() {
	if (!isInitialized()) {
		initialized = true;
	}
	return initialized;
}

template<typename R>
inline bool BaseComponent<R>::isInitialized() {
	return initialized;
}

template<typename R>
void BaseComponent<R>::resume() {
}

template<typename R>
void BaseComponent<R>::startUpdate(double deltaTime) {
}

template<typename R>
void BaseComponent<R>::endUpdate(double deltaTime) {
}

template<typename R>
void BaseComponent<R>::pause() {
}

template<typename R>
inline bool BaseComponent<R>::hasRequestExit() {
	return requestExit;
}
