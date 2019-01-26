#pragma once

#include "Ease.h"

class LinearEase : public Ease {
public:
	LinearEase();
	virtual ~LinearEase();

	virtual double update(double min, double max, double timePercent) const override;
};
