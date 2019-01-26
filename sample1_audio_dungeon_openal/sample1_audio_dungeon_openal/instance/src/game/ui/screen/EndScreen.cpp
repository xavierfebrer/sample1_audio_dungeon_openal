#include "../../../../include/EndScreen.h"

EndScreen::EndScreen(Game & game, bool win)
	: BaseScreen(game), win(win) {
}

EndScreen::~EndScreen() {
}

void EndScreen::create() {
	BaseScreen::create();
	endMusic = std::shared_ptr<OpenALSound>(new OpenALSound(win ? "assets/sound/music_win.wav" : "assets/sound/music_lose.wav"));
	endMusic->init(0.75f);
	endMusic->play();
}

void EndScreen::initViews() {
}

void EndScreen::resume() {
	BaseScreen::resume();
}

void EndScreen::update(double deltaTime) {
	BaseScreen::update(deltaTime);
}

void EndScreen::render(double deltaTime) {
	BaseScreen::render(deltaTime);
}

void EndScreen::pause() {
	BaseScreen::pause();
}

void EndScreen::openMainMenuScreen() {
	game.setScreen(std::make_unique<MainMenuScreen>(game));
}
