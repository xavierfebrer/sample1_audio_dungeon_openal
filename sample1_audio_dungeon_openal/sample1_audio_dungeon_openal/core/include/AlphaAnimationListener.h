#pragma once

class AlphaAnimationListener {
public:
	AlphaAnimationListener() {}
	virtual ~AlphaAnimationListener() {}

	virtual void onAnimationStarted(double value) = 0;
	virtual void onAnimationUpdated(double value) = 0;
	virtual void onAnimationEnded(double value) = 0;
};