#include "../../../../include/MainMenuScreen.h"

MainMenuScreen::MainMenuScreen(Game & game)
	: BaseScreen(game) {
}

MainMenuScreen::~MainMenuScreen() {
}

void MainMenuScreen::create() {
	BaseScreen::create();
}

void MainMenuScreen::initViews() {
}

void MainMenuScreen::resume() {
	BaseScreen::resume();
}

void MainMenuScreen::update(double deltaTime) {
	BaseScreen::update(deltaTime);
	openGameScreen();
}

void MainMenuScreen::render(double deltaTime) {
	BaseScreen::render(deltaTime);
}

void MainMenuScreen::pause() {
	BaseScreen::pause();
}

void MainMenuScreen::openGameScreen() {
	game.setScreen(std::make_unique<GameScreen>(game, 1, 1));
}

void MainMenuScreen::exitGame() {
	game.exit();
}
