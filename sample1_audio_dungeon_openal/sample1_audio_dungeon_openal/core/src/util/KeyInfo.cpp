#include "../../include/KeyInfo.h"

KeyInfo::KeyInfo(bool pressed) {
	set(pressed);
}

KeyInfo::~KeyInfo() {
}

void KeyInfo::set(bool pressed) {
	this->pressed = pressed;
}
