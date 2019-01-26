#pragma once

#include "AbsEaseAnimation.h"
#include "Ease.h"
#include "MoveAnimationListener.h"

class MoveEaseAnimation : public AbsEaseAnimation {
private:
	const Vec2<> start;
	const Vec2<> end;
	Vec2<> current;
	double percentCurrentDuration;
	std::unique_ptr<Ease> ease;
	std::shared_ptr<MoveAnimationListener> animationListener;
protected:
	virtual void updateCurrent() override;
	virtual void startEvent() override;
	virtual void updateEvent() override;
	virtual void endEvent() override;
public:
	MoveEaseAnimation(const Vec2<> & start, const Vec2<> & end, double startDelay, double duration, std::unique_ptr<Ease> ease,
		const std::shared_ptr<MoveAnimationListener> & animationListener);
	virtual ~MoveEaseAnimation();

	const Vec2<>& getStart();
	const Vec2<>& getCurrent();
	const Vec2<>& getEnd();
};

