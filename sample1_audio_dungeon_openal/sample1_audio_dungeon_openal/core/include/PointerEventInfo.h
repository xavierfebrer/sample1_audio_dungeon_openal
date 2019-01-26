#pragma once

#include "PointerEvent.h"

class PointerEventInfo {
public:
	int pointerIndex;
	PointerEvent pointerEvent;
	int xScreen;
	int yScreen;
	double xViewCamera;
	double yViewCamera;

	PointerEventInfo(int pointerIndex);
	PointerEventInfo(int pointerIndex, PointerEvent pointerEvent);
	PointerEventInfo(int pointerIndex, int xScreen, int yScreen, double xViewCamera, double yViewCamera);
	PointerEventInfo(int pointerIndex, PointerEvent pointerEvent, int xScreen, int yScreen, double xViewCamera, double yViewCamera);
	virtual ~PointerEventInfo();
};

