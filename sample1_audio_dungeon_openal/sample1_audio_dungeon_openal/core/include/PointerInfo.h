#pragma once

class PointerInfo {
public:
	bool pressed;
	int x, y;

	PointerInfo(int x = 0, int y = 0, bool pressed = false);
	virtual ~PointerInfo();

	void set(int x, int y, bool pressed);
	void setPos(int x, int y);
	void setPressed(bool pressed);

	PointerInfo& operator=(const PointerInfo & other) {
		pressed = other.pressed;
		x = other.x;
		y = other.y;
		return *this;
	}
};

