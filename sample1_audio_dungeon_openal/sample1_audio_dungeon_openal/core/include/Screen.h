#pragma once

#include "Game.h"
#include "ViewManager.h"

class Screen {
protected:
	Game & game;
	ViewManager viewManager;
public:
	Screen(Game & game);
	virtual ~Screen() = 0;

	virtual void create() = 0;
	virtual void resume() = 0;
	virtual void update(double deltaTime) = 0;
	virtual void render(double deltaTime) = 0;
	virtual void pause() = 0;
};

