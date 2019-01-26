#include "../../../../include/Padding.h"

const double Padding::MIN_PADDING = 0;
const double Padding::MAX_PADDING = 1;

Padding::Padding() : Padding(Padding::MIN_PADDING, Padding::MIN_PADDING) {
}

Padding::Padding(const Padding & padding) : Padding(padding.verticalPercent, padding.horizontalPercent) {
}

Padding::Padding(double verticalPercent, double horizontalPercent) {
	setVerticalPercent(verticalPercent);
	setHorizontalPercent(horizontalPercent);
}

Padding::~Padding() {
}

double Padding::getVerticalPercent() {
	return verticalPercent;
}

void Padding::setVerticalPercent(double verticalPercent) {
	this->verticalPercent = Util::minMax(verticalPercent, Padding::MIN_PADDING, Padding::MAX_PADDING);
}

double Padding::getHorizontalPercent() {
	return horizontalPercent;
}

void Padding::setHorizontalPercent(double horizontalPercent) {
	this->horizontalPercent = Util::minMax(horizontalPercent, Padding::MIN_PADDING, Padding::MAX_PADDING);
}
