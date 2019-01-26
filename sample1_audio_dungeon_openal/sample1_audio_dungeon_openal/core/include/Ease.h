#pragma once

#include "Util.h"

class Ease {
public:
	Ease();
	virtual ~Ease();

	virtual double update(double startValue, double endValue, double timePercent) const = 0;
};

