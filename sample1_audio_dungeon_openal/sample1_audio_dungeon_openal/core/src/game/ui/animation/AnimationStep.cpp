#include "../../../../include/AnimationStep.h"

AnimationStep::AnimationStep(double time, TextureRegion2D & item) : time(0), item(item) {
	setTime(time);
	currentTime = time;
	restart();
}

AnimationStep::~AnimationStep() {
}

const double AnimationStep::update(double deltaTime, double scale) {
	deltaTime *= scale;
	if (deltaTime <= currentTime) {
		currentTime -= deltaTime;
		return 0;
	} else {
		deltaTime = deltaTime - currentTime;
		currentTime = 0;
		return deltaTime;
	}
}

void AnimationStep::restart() {
	currentTime = time;
}

const bool AnimationStep::isFinished() const{
	return currentTime <= 0;
}

void AnimationStep::finish() {
	currentTime = 0;
}

const double AnimationStep::getTime() {
	return time;
}

void AnimationStep::setTime(double time) {
	if (time <= 0) {
		throw "time parameter must be > 0.";
	}
	this->time = time;
}

TextureRegion2D& AnimationStep::getItem() {
	return item;
}

std::vector<std::unique_ptr<AnimationStep>> AnimationStep::createList(TextureRegion2D & item, double time) {
	std::vector<std::unique_ptr<AnimationStep>> steps;
	steps.push_back(std::make_unique<AnimationStep>(time, item));
	return steps;
}

std::vector<std::unique_ptr<AnimationStep>> AnimationStep::createList(std::vector<TextureRegion2D> & items, double time) {
	std::vector<std::unique_ptr<AnimationStep>> steps;
	for (size_t i = 0; i < items.size(); ++i) {
		steps.push_back(std::make_unique<AnimationStep>(time, items[i]));
	}
	return steps;
}
