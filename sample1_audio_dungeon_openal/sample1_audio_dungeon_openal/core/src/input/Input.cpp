#include "../../include/Input.h"

Input::Input()
	: BaseComponent() {
	for (int i = 0; i < MAX_POINTERS; i++) {
		prevPointers.push_back(PointerInfo());
		pointers.push_back(PointerInfo());
	}
}

Input::~Input() {
}

BaseComponentReadiness Input::isReady() {
	return isInitialized() ? BaseComponentReadiness::READY : BaseComponentReadiness::NOT_READY;
}

bool Input::isPrevPointerPressed(int pointerIndex) {
	return prevPointers[pointerIndex].pressed;
}

bool Input::isPointerPressed(int pointerIndex) {
	return pointers[pointerIndex].pressed;
}

PointerInfo Input::getPrevPointerInfo(int pointerIndex) {
	return prevPointers[pointerIndex];
}

PointerInfo Input::getPointerInfo(int pointerIndex) {
	return pointers[pointerIndex];
}

bool Input::isPrevKeyPressed(int keyIndex) {
	return prevKeyMap[keyIndex].pressed;
}

bool Input::isKeyPressed(int keyIndex) {
	return keyMap[keyIndex].pressed;
}

std::map<int, KeyInfo> & Input::getPrevKeyInfo() {
	return prevKeyMap;
}

std::map<int, KeyInfo> & Input::getKeyInfo() {
	return keyMap;
}
