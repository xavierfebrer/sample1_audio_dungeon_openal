#pragma once

#include "Util.h"
#include "TextureRegion2D.h"

class AnimationStep {
private:
	double time;
	double currentTime;
	TextureRegion2D & item;
public:
	AnimationStep(double time, TextureRegion2D & item);
	virtual ~AnimationStep();

	const double update(double deltaTime, double scale = 1.0);
	void restart();
	const bool isFinished() const;
	void finish();
	const double getTime();
	void setTime(double time);
	TextureRegion2D& getItem();

	static std::vector<std::unique_ptr<AnimationStep>> createList(TextureRegion2D & item, double time = std::numeric_limits<double>::max());
	static std::vector<std::unique_ptr<AnimationStep>> createList(std::vector<TextureRegion2D> & items, double time = std::numeric_limits<double>::max());
};

