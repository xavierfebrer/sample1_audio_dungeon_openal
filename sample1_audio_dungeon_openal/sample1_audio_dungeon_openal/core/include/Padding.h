#pragma once

#include "Util.h"

class Padding {
private:
	double verticalPercent;
	double horizontalPercent;
public:
	static const double MAX_PADDING;
	static const double MIN_PADDING;

	Padding();
	Padding(const Padding & padding);
	Padding(double verticalPercent, double horizontalPercent);
	virtual ~Padding();

	double getVerticalPercent();
	void setVerticalPercent(double verticalPercent);
	double getHorizontalPercent();
	void setHorizontalPercent(double horizontalPercent);
};

