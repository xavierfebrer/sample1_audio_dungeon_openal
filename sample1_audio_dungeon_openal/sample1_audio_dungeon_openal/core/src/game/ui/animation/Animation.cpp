#include "../../../../include/Animation.h"

Animation::Animation(std::vector<std::unique_ptr<AnimationStep>> steps, int loopTimes) {
	setSteps(std::move(steps));
	setLoopTimes(loopTimes);
}

Animation::~Animation() {
}

void Animation::setLoopTimes(int loopTimes) {
	if (loopTimes == 0) {
		throw "loopTimes must be negative (infinite loops) or greater than 0.";
	}
	initialLoopsLeft = loopTimes;
	loopsLeft = loopTimes;
}

const bool Animation::isInfinite() const {
	return initialLoopsLeft < 0;
}

const int Animation::getLoopsLeft() {
	return loopsLeft;
}

void Animation::decreaseLoopsLeft() {
	loopsLeft -= 1;
}

const bool Animation::hasEnded() {
	return loopsLeft == 0 && getCurrentStep().isFinished();
}

void Animation::update(double deltaTime, double scale) {
	deltaTimeLeft = getCurrentStep().update(deltaTime, scale);
	if (deltaTimeLeft > 0) {
		if (nextCurrentStepIndex()) {
			update(deltaTimeLeft);
		}
	}
}

const bool Animation::nextCurrentStepIndex() {
	if (currentStepIndex < steps.size() - 1) {
		currentStepIndex++;
	} else if (getLoopsLeft() == -1) {
		currentStepIndex = 0;
	} else if (getLoopsLeft() == 1) {
		decreaseLoopsLeft();
		return false;
	} else if (getLoopsLeft() > 0) {
		decreaseLoopsLeft();
		currentStepIndex = 0;
	} else {
		return false;
	}
	getCurrentStep().restart();
	return true;
}

void Animation::setSteps(std::vector<std::unique_ptr<AnimationStep>> newSteps) {
	if (newSteps.empty()) { throw "steps parameter must not be null or empty."; }
	steps.clear();
	steps.swap(newSteps);
	restart();
}

void Animation::restart() {
	currentStepIndex = 0;
	loopsLeft = initialLoopsLeft;
	for (size_t i = 0; i < steps.size(); i++) {
		steps[i]->restart();
	}
}

AnimationStep& Animation::getCurrentStep() {
	return *steps[currentStepIndex];
}

const double Animation::getDuration() const{
	double duration = 0;
	for (size_t i = 0; i < steps.size(); i++) {
		duration += steps[i]->getTime();
	}
	if(initialLoopsLeft > 0){
		duration *= initialLoopsLeft;
	}
	return duration;
}
