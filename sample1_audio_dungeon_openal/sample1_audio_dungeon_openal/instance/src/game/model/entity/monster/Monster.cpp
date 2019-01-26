#include "../../../../../include/Monster.h"

Monster::Monster(GameWorld & gameWorld, int x, int y)
	: Entity(gameWorld), x(x), y(y) {
}

Monster::~Monster() {
}

void Monster::create() {
	roar = std::shared_ptr<OpenALSound>(new OpenALSound("assets/sound/Monster-Snoring.wav"));
	roar->init(0.0f, true);
	startRoaring();
}

void Monster::update(double deltaTime) {
}

void Monster::render(double deltaTime) {
}

void Monster::collision(Entity * other) {
}

int Monster::getX() {
	return x;
}

void Monster::setX(int x) {
	this->x = x;
}

int Monster::getY() {
	return y;
}

void Monster::setY(int y) {
	this->y = y;
}

void Monster::startRoaring() {
	roar->play();
}

void Monster::stopRoaring() {
	roar->stop();
}

void Monster::setRoarVolume(float volume) {
	roar->setVolume(volume);
}
