#include "../../include/Audio.h"

Audio::Audio()
	: BaseComponent() {
}

Audio::~Audio() {
}

BaseComponentReadiness Audio::isReady() {
	return isInitialized() ? BaseComponentReadiness::READY : BaseComponentReadiness::NOT_READY;
}
