#include "../../../../include/LogoScreen.h"

LogoScreen::LogoScreen(Game & game)
	: BaseScreen(game) {
}

LogoScreen::~LogoScreen() {
}

void LogoScreen::create() {
	BaseScreen::create();
}

void LogoScreen::initViews() {
}

void LogoScreen::resume() {
	BaseScreen::resume();
}

void LogoScreen::update(double deltaTime) {
	BaseScreen::update(deltaTime);
	totalTime += deltaTime;
	openMainMenuScreen();
	if (totalTime > TARGET_TOTAL_TIME) {
		openMainMenuScreen();
	}
}

void LogoScreen::render(double deltaTime) {
	BaseScreen::render(deltaTime);
}

void LogoScreen::pause() {
	BaseScreen::pause();
}

void LogoScreen::openMainMenuScreen() {
	game.setScreen(std::make_unique<MainMenuScreen>(game));
}