#include "../../../../../include/PointerEventInfo.h"

PointerEventInfo::PointerEventInfo(int pointerIndex) : PointerEventInfo(pointerIndex, PointerEvent::IDLE, 0, 0, 0, 0) {
}

PointerEventInfo::PointerEventInfo(int pointerIndex, PointerEvent pointerEvent) : PointerEventInfo(pointerIndex, pointerEvent, 0, 0, 0, 0) {
}

PointerEventInfo::PointerEventInfo(int pointerIndex, int xScreen, int yScreen, double xViewCamera, double yViewCamera) : PointerEventInfo(pointerIndex, PointerEvent::IDLE, xScreen, yScreen, xViewCamera, yViewCamera) {
}

PointerEventInfo::PointerEventInfo(int pointerIndex, PointerEvent pointerEvent, int xScreen, int yScreen, double xViewCamera, double yViewCamera) {
	this->pointerIndex = pointerIndex;
	this->pointerEvent = pointerEvent;
	this->xScreen = xScreen;
	this->yScreen = yScreen;
	this->xViewCamera = xViewCamera;
	this->yViewCamera = yViewCamera;
}

PointerEventInfo::~PointerEventInfo() {
}
