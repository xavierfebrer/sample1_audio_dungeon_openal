#pragma once

#include "Util.h"

#include "BaseComponent.h"
#include "Audio.h"
#include "Graphics.h"

class Assets : public BaseComponent<> {
public:
	static const std::string PATH_ASSETS;
	static const std::string PATH_IMAGE;
	static const std::string PATH_AUDIO;
	static const std::string PATH_MUSIC;
	static const std::string PATH_SOUND;

	Assets();
	virtual ~Assets() override;

	virtual BaseComponentReadiness isReady() override;

	bool loadAllResources();
private:
	bool allResourcesLoaded;
};
