#include "../../../../include/GameScreen.h"

GameScreen::GameScreen(Game & game, int worldIndex, int levelIndex)
	: BaseScreen(game),
	gameWorld(GameWorld(game)), worldIndex(worldIndex), levelIndex(levelIndex) {
}

GameScreen::~GameScreen() {
}

void GameScreen::create() {
	BaseScreen::create();
	gameWorld.init();
}

void GameScreen::initViews() {
}

void GameScreen::goBack() {
	game.setScreen(std::make_unique<MainMenuScreen>(game));
}

void GameScreen::resume() {
	BaseScreen::resume();
}

void GameScreen::update(double deltaTime) {
	BaseScreen::update(deltaTime);
	gameWorld.update(deltaTime);
	if (gameWorld.hasHeroWon()) {
		if (timerEndingWin > 0) {
			timerEndingWin -= deltaTime;
		} else {
			game.setScreen(std::make_unique<EndScreen>(game, true));
		}
	} else if (gameWorld.hasHeroLost()) {
		if (timerEndingLose > 0) {
			timerEndingLose -= deltaTime;
		} else {
			game.setScreen(std::make_unique<EndScreen>(game, false));
		}
	}
}

void GameScreen::render(double deltaTime) {
	gameWorld.render(deltaTime);
	BaseScreen::render(deltaTime);
}

void GameScreen::pause() {
	BaseScreen::pause();
}
