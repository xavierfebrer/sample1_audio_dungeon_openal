#pragma once

#include "BaseComponent.h"

class Audio : public BaseComponent<> {
public:
	Audio();
	virtual ~Audio() override;

	virtual BaseComponentReadiness isReady() override;
};