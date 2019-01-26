#pragma once

#include "Util.h"

class Screen;

class Game {
public:
	Game();
	virtual ~Game();

	virtual bool create() = 0;
	virtual void loop() = 0;
	virtual void resume() = 0;
	virtual void pause() = 0;
	virtual void setScreen(std::unique_ptr<Screen> newScreen) = 0;
	virtual void exit() = 0;
};