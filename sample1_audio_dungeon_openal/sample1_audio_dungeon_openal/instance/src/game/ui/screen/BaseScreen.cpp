#include "../../../../include/BaseScreen.h"

BaseScreen::BaseScreen(Game & game)
	: Screen(game) {
}

BaseScreen::~BaseScreen() {
}

void BaseScreen::create() {
	initViews();
}

void BaseScreen::resume() {
	viewManager.resume();
}

void BaseScreen::update(double deltaTime) {
	viewManager.update(deltaTime);
}

void BaseScreen::render(double deltaTime) {
	viewManager.render(deltaTime);
}

void BaseScreen::pause() {
	viewManager.pause();
}
