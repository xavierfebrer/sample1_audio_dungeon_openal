#pragma once

#include "Util.h"

class MoveAnimationListener {
public:
	virtual ~MoveAnimationListener() {}

	virtual void onAnimationStarted(const Vec2<> & value) = 0;
	virtual void onAnimationUpdated(const Vec2<> & value) = 0;
	virtual void onAnimationEnded(const Vec2<> & value) = 0;
};
