#include "../../include/AbsEaseAnimation.h"

AbsEaseAnimation::AbsEaseAnimation(double startDelay, double duration) {
	this->startDelay = startDelay >= 0 ? startDelay : 0;
	this->duration = duration >= 0 ? duration : 0;
	currentStartDelay = 0;
	currentDuration = 0;
	started = false;
	ended = false;
}

AbsEaseAnimation::~AbsEaseAnimation() {
}

void AbsEaseAnimation::update(double deltaTime) {
	if (currentStartDelay >= startDelay) {
		currentDuration += deltaTime;
		if (currentDuration < duration) {
			if (!started) {
				started = true;
				startEvent();
			}
			updateCurrent();
			updateEvent();
		} else if (!ended) {
			ended = true;
			endEvent();
		}
	} else {
		currentStartDelay += deltaTime;
	}
}

double AbsEaseAnimation::getStartDelay() {
	return startDelay;
}

double AbsEaseAnimation::getDuration() {
	return duration;
}
