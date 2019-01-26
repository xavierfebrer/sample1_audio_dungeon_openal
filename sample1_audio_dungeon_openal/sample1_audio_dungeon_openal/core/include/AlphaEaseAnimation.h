#pragma once

#include "AbsEaseAnimation.h"
#include "Ease.h"
#include "AlphaAnimationListener.h"

class AlphaEaseAnimation : public AbsEaseAnimation {
private:
	const double start;
	const double end;
	double current;
	double percentCurrentDuration;
	std::unique_ptr<Ease> ease;
	std::shared_ptr<AlphaAnimationListener> animationListener;
protected:
	virtual void updateCurrent() override;
	virtual void startEvent() override;
	virtual void updateEvent() override;
	virtual void endEvent() override;
public:
	AlphaEaseAnimation(double start, double end, double startDelay, double duration, std::unique_ptr<Ease> ease,
		const std::shared_ptr<AlphaAnimationListener> & animationListener);
	virtual ~AlphaEaseAnimation();

	double getStart();
	double getCurrent();
	double getEnd();
};

