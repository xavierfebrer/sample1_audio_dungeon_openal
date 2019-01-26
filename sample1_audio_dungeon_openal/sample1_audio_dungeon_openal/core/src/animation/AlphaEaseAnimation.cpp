#include "../../include/AlphaEaseAnimation.h"

AlphaEaseAnimation::AlphaEaseAnimation(double start, double end, double startDelay, double duration, std::unique_ptr<Ease> ease,
	const std::shared_ptr<AlphaAnimationListener> & animationListener) 
	: AbsEaseAnimation(startDelay, duration), start(start), end(end), current(start), ease(std::move(ease)), animationListener(animationListener){
}

AlphaEaseAnimation::~AlphaEaseAnimation() {
}

void AlphaEaseAnimation::updateCurrent() {
	percentCurrentDuration = currentDuration / duration;
	current = ease->update(start, end, percentCurrentDuration);
}

void AlphaEaseAnimation::startEvent() {
	if (animationListener) {
		animationListener->onAnimationStarted(start);
	}
}

void AlphaEaseAnimation::updateEvent() {
	if (animationListener) {
		animationListener->onAnimationUpdated(current);
	}
}

void AlphaEaseAnimation::endEvent() {
	if (animationListener) {
		animationListener->onAnimationEnded(end);
	}
}

double AlphaEaseAnimation::getStart() {
	return start;
}

double AlphaEaseAnimation::getCurrent() {
	return current;
}

double AlphaEaseAnimation::getEnd() {
	return end;
}