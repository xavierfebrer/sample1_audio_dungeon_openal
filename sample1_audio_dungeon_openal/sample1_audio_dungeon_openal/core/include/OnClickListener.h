#pragma once

#include "Util.h"
#include "View.h"

class OnClickListener {
public:
	OnClickListener() {}
	virtual ~OnClickListener() {}

	virtual void onClickDown(View & view) = 0;
	virtual void onClickUp(View & view) = 0;
};