#include "World.h"

World::World(int width, int height, int gridSize) {
	this->height = height;
	this->width = width;
	this->gridSize = gridSize;
	this->world = std::vector<std::vector<float>>((int)(width/gridSize), std::vector<float>((int)(height/gridSize)));
	this->world = NoiseMap::createNoiseMap(world);

	this->backGround.create(width, height);
}

void World::simulateWorld(sf::RenderWindow& window) {
	Simulator::drawWorld(window, gridSize, backGround, world);
}

