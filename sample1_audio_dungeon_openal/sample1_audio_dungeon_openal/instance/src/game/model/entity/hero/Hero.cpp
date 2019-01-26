#include "../../../../../include/Hero.h"
#include "../../../../../include/Exit.h"
#include "../../../../../include/Monster.h"
#include "../../../../../../core/include/Hack3dEngine.h"

Hero::Hero(GameWorld & gameWorld, int x, int y, int life)
	: Entity(gameWorld), x(x), y(y), dir(0), life(life), reachedExit(false) {
}

Hero::~Hero() {
}

void Hero::create() {
	gameWorld.renderMap();
	gameWorld.calculateConstantSounds();
}

void Hero::update(double deltaTime) {
	if (!reachedExit && life > 0) {
		Hack3dEngine* engine = Hack3dEngine::get();
		std::shared_ptr<Input> input = engine->input;
		std::map<int, KeyInfo> prevKeys = input->getPrevKeyInfo();
		std::map<int, KeyInfo> currentKeys = input->getKeyInfo();
		int prevKeysSize = prevKeys.size();
		int currentKeysSize = currentKeys.size();
		if (!prevKeys[GLFW_KEY_W].pressed && currentKeys[GLFW_KEY_W].pressed) {
			moveForward();
		} else if (!prevKeys[GLFW_KEY_S].pressed && currentKeys[GLFW_KEY_S].pressed) {
			moveBackwards();
		} else if (!prevKeys[GLFW_KEY_A].pressed && currentKeys[GLFW_KEY_A].pressed) {
			turnLeft();
		} else if (!prevKeys[GLFW_KEY_D].pressed && currentKeys[GLFW_KEY_D].pressed) {
			turnRight();
		}
	}
}

void Hero::render(double deltaTime) {
}

void Hero::collision(Entity * other) {
	if (Exit * exit = dynamic_cast<Exit*>(other)) {
		reachedExit = true;
	}
	if (Monster * monster = dynamic_cast<Monster*>(other)) {
		life--;
	}
}

void Hero::moveForward() {
	if (dir == 0) {
		move(x, y - 1, dir);
	} else if (dir == 3) {
		move(x - 1, y, dir);
	} else if (dir == 2) {
		move(x, y + 1, dir);
	} else {
		move(x + 1, y, dir);
	}
}

void Hero::moveBackwards() {
	if (dir == 0) {
		move(x, y + 1, dir);
	} else if (dir == 3) {
		move(x + 1, y, dir);
	} else if (dir == 2) {
		move(x, y - 1, dir);
	} else {
		move(x - 1, y, dir);
	}
}

void Hero::turnLeft() {
	if (dir == 0) {
		move(x, y, 3);
	} else if (dir == 3) {
		move(x, y, 2);
	} else if (dir == 2) {
		move(x, y, 1);
	} else {
		move(x, y, 0);
	}
}

void Hero::turnRight() {
	if (dir == 0) {
		move(x, y, 1);
	} else if (dir == 1) {
		move(x, y, 2);
	} else if (dir == 2) {
		move(x, y, 3);
	} else {
		move(x, y, 0);
	}
}

int Hero::getX() {
	return x;
}

int Hero::getY() {
	return y;
}

int Hero::getDir() {
	return dir;
}

void Hero::setLife(int life) {
	this->life = life;
}

int Hero::getLife() {
	return life;
}

bool Hero::hasReachedExit() {
	return reachedExit;
}

void Hero::move(int newX, int newY, int newHeroDir) {
	if (gameWorld.movePlayerTo(newX, newY)) {
		x = newX;
		y = newY;
	}
	dir = newHeroDir;
	gameWorld.renderMap();
}
