#include "../../include/PointerInfo.h"

PointerInfo::PointerInfo(int x, int y, bool pressed) {
	set(x, y, pressed);
}

PointerInfo::~PointerInfo() {
}

void PointerInfo::set(int x, int y, bool pressed) {
	setPos(x, y);
	setPressed(pressed);
}

void PointerInfo::setPos(int x, int y) {
	this->x = x;
	this->y = y;
}

void PointerInfo::setPressed(bool pressed) {
	this->pressed = pressed;
}
