#pragma once

#include "Util.h"

class EaseAnimation {
public:
	virtual void update(double deltaTime) = 0;
};