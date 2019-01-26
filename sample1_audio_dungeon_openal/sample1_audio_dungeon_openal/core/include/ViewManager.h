#pragma once

#include "Util.h"
#include "View.h"
#include "Game.h"
#include "PointerEventInfo.h"

class ViewManager {
public:
	ViewManager(Game & game);
	virtual ~ViewManager();

	void addView(const std::shared_ptr<View> & view);
	int removeView(const std::shared_ptr<View> & view);
	void clear();
	void resume();
	void update(double deltaTime);
	void render(double deltaTime);
	void pause();
protected:
	std::vector<std::shared_ptr<View>> views;
private:
	Game & game;
	std::vector<std::unique_ptr<PointerEventInfo>> pointerEvents;

	void updateInput(double deltaTime);
	void updatePointerEvents(double deltaTime);
	void sendPointerEventData(double deltaTime);
	void updateState(double deltaTime);
};

