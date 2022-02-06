#include "World.h"

World::World(int width, int height, int gridSize) {
	this->height = height;
	this->width = width;
	this->gridSize = gridSize;
	this->world = std::vector<std::vector<float>>((int)(width/gridSize), std::vector<float>((int)(height/gridSize)));
	this->world = NoiseMap::createNoiseMap(world);

	this->backGround.create(width, height);
	creatureVector.push_back(Creature(34, 400, 5, 5, sf::Color(1, 1, 1)));
	creatureVector.push_back(Creature(40, 400, 5, 5, sf::Color(1, 1, 1)));
	creatureVector.push_back(Creature(600, 300, 5, 5, sf::Color(1, 1, 1)));
	creatureVector.push_back(Creature(500, 400, 5, 5, sf::Color(1, 1, 1)));
}

void World::drawWorld(sf::RenderWindow& window) {
	MapCreator::drawMap(window, gridSize, world);
	CreatureManager::drawCreatures(window, gridSize, creatureVector, width , height);
}



