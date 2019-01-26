#include "../../../../../include/Terrain.h"


Terrain::Terrain(GameWorld & gameWorld, std::vector<std::vector<int>> map)
	: Entity(gameWorld), map(map) {
}

Terrain::~Terrain() {
}

void Terrain::create() {
}

void Terrain::update(double deltaTime) {
}

void Terrain::render(double deltaTime) {
}

void Terrain::collision(Entity * other) {
}

bool Terrain::isBlocked(int x, int y) {
	if (y > 0 && y < map.size()) {
		if (x > 0 && x < map[y].size()) {
			return map[y][x];
		}
	}
	return true;
}

std::vector<std::vector<int>> Terrain::getMap() {
	return map;
}
