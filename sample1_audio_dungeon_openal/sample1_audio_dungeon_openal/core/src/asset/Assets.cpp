#include "../../include/Assets.h"

const std::string Assets::PATH_ASSETS = "assets/";
const std::string Assets::PATH_IMAGE = PATH_ASSETS + "image/";
const std::string Assets::PATH_AUDIO = PATH_ASSETS + "audio/";
const std::string Assets::PATH_MUSIC = PATH_AUDIO + "music/";
const std::string Assets::PATH_SOUND = PATH_AUDIO + "sound/";

Assets::Assets()
	: BaseComponent(), allResourcesLoaded(false) {
}

Assets::~Assets() {
}

BaseComponentReadiness Assets::isReady() {
	return isInitialized() ? BaseComponentReadiness::READY : BaseComponentReadiness::NOT_READY;
}

bool Assets::loadAllResources() {
	if (!allResourcesLoaded) {
		allResourcesLoaded = true;
	}
	return allResourcesLoaded;
}
