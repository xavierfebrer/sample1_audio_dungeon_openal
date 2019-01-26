#pragma once

#include "Util.h"
#include "AnimationStep.h"

class Animation {
private:
	 double deltaTimeLeft;
	 int initialLoopsLeft;
	 int loopsLeft;
	 int currentStepIndex;
	 std::vector<std::unique_ptr<AnimationStep>> steps;
public:
	Animation(std::vector<std::unique_ptr<AnimationStep>> steps, int loopTimes = -1);
	virtual ~Animation();

	void setLoopTimes(int loopTimes);
	const bool isInfinite() const;
	const int getLoopsLeft();
	void decreaseLoopsLeft();
	const bool hasEnded() ;
	void update(double deltaTime, double scale = 1.0);
	const bool nextCurrentStepIndex();
	void setSteps(std::vector<std::unique_ptr<AnimationStep>> steps);
	void restart();
	AnimationStep& getCurrentStep();
	const double getDuration() const;
};
