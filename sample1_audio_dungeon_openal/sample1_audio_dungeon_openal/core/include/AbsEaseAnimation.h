#pragma once

#include "EaseAnimation.h"

class AbsEaseAnimation : public EaseAnimation {
protected:
	double startDelay;
	double duration;
	double currentStartDelay;
	double currentDuration;
	bool started;
	bool ended;

	virtual void updateCurrent() = 0;
	virtual void startEvent() = 0;
	virtual void updateEvent() = 0;
	virtual void endEvent() = 0;
public:
	AbsEaseAnimation(double startDelay, double duration);
	virtual ~AbsEaseAnimation();

	void update(double deltaTime);
	double getStartDelay();
	double getDuration();
};

