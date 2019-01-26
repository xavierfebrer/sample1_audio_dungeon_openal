#pragma once

#include "../../core/include/Game.h"
#include "Constants.h"

class Sample1AudioDungeonGameOpenALGame : public Game {
public:
	static int execute();

	Sample1AudioDungeonGameOpenALGame();
	virtual ~Sample1AudioDungeonGameOpenALGame() override;

	virtual bool create() override;
	virtual void loop() override;
	virtual void resume() override;
	virtual void pause() override;
	virtual void setScreen(std::unique_ptr<Screen> newScreen) override;
	virtual void exit() override;
private:
	bool initialized;
	bool running;
	bool ended;
	std::unique_ptr<Screen> currentScreen;
	std::unique_ptr<Screen> newScreen;

	bool init();
	bool waitForReadyState();
	bool startGame();
	void update(double deltaTime);
	void render(double deltaTime);
	void checkNewScreen();
};

