#include "../../../../../include/Exit.h"

Exit::Exit(GameWorld & gameWorld, int x, int y)
	: Entity(gameWorld), x(x), y(y) {
}

Exit::~Exit() {
}

void Exit::create() {
	waterfall = std::shared_ptr<OpenALSound>(new OpenALSound("assets/sound/waterfall.wav"));
	waterfall->init(0.0f, true);
	startWaterfall();
}

void Exit::update(double deltaTime) {
}

void Exit::render(double deltaTime) {
}

void Exit::collision(Entity * other) {
}

int Exit::getX() {
	return x;
}

int Exit::getY() {
	return y;
}

void Exit::startWaterfall() {
	waterfall->play();
}

void Exit::stopWaterfall() {
	waterfall->stop();
}

void Exit::setWaterfallVolume(float volume) {
	waterfall->setVolume(volume);
}
