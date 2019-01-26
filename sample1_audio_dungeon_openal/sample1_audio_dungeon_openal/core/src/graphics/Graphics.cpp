#include "../../include/Graphics.h"

Graphics::Graphics()
	: BaseComponent() {
}

Graphics::~Graphics() {
}

BaseComponentReadiness Graphics::isReady() {
	return isInitialized() ? BaseComponentReadiness::READY : BaseComponentReadiness::NOT_READY;
}