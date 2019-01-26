#include "../../../include/LinearEase.h"

LinearEase::LinearEase() : Ease() {
}

LinearEase::~LinearEase() {
}

double LinearEase::update(double start, double end, double timePercent) const {
	if (start < end) {
		return start + ((end - start) * timePercent);
	} else {
		return start - ((start - end) * timePercent);
	}
}