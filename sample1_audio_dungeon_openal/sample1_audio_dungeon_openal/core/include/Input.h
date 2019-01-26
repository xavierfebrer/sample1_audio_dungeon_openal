#pragma once

#include "Util.h"

#include "BaseComponent.h"

class Input : public BaseComponent<> {
public:
	static const int MAX_POINTERS = 20;

	Input();
	virtual ~Input() override;

	virtual BaseComponentReadiness isReady() override;

	bool isPrevPointerPressed(int pointerIndex);
	bool isPointerPressed(int pointerIndex);
	PointerInfo getPrevPointerInfo(int pointerIndex);
	PointerInfo getPointerInfo(int pointerIndex);
	bool isPrevKeyPressed(int keyIndex);
	bool isKeyPressed(int keyIndex);
	std::map<int, KeyInfo> & getPrevKeyInfo();
	std::map<int, KeyInfo> & getKeyInfo();
protected:
	std::vector<PointerInfo> prevPointers;
	std::vector<PointerInfo> pointers;
	std::map<int, KeyInfo> prevKeyMap;
	std::map<int, KeyInfo> keyMap;
};
