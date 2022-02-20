#include "World.h"

World::World(int width, int height, int gridSize) {
	this->_height = height;
	this->_width = width;
	this->_gridSize = gridSize;
	this->_worldMap = std::vector<std::vector<float>>((int)(width/gridSize), std::vector<float>((int)(height/gridSize)));
	this->_worldMap = NoiseMap::createNoiseMap(_worldMap);
	this->_temperatureMap = std::vector<std::vector<float>>((int)(width/gridSize), std::vector<float>((int)(height/gridSize)));
	this->_temperatureMap = NoiseMap::createNoiseMap(_temperatureMap);
	MapCreator::drawMap(_backGround, _gridSize, _worldMap, _temperatureMap);

	// tmp
	for (int y = 0; y < 4; y++) {
		CreatureManager::createSpecies(_speciesVector, sf::Color(rand(), rand(), rand()), 15, y);
		for (int i = 0; i < 25; i++) {
			CreatureManager::createCreature(_creatureVector, _speciesVector[y], (float)rand() / RAND_MAX * width, (float)rand() / RAND_MAX * height);
		}
	}
}

void World::drawWorld(sf::RenderWindow& window) {
	sf::Sprite sprite(_backGround.getTexture());
	window.draw(sprite);

	CreatureManager::drawCreatures(window, _gridSize, _creatureVector, _width , _height);
}
void World::simulateWorld(sf::RenderWindow& window, sf::Time deltaTime) {
	CreatureManager::moveAllCreature(_creatureVector, deltaTime);
}



