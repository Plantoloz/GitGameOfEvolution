#include "World.h"

World::World(int width, int height, int gridSize) {
	this->_height = height;
	this->_width = width;
	this->_gridSize = gridSize;
	this->_worldMap = std::vector<std::vector<float>>((int)(width/gridSize), std::vector<float>((int)(height/gridSize)));
	this->_worldMap = NoiseMap::createNoiseMap(_worldMap, 3.5);
	this->_temperatureMap = std::vector<std::vector<float>>((int)(width/gridSize), std::vector<float>((int)(height/gridSize)));
	this->_temperatureMap = NoiseMap::createNoiseMap(_temperatureMap, 2);
	MapCreator::drawMap(_backGround, _gridSize, _worldMap, _temperatureMap);

	

	// tmp
	for (int y = 0; y < 10; y++) {
		CreatureManager::createSpecies(_speciesVector, sf::Color(rand(), rand(), rand()), (float)rand() / RAND_MAX * 15 + 7.5, y, (float)rand() / (RAND_MAX), (float)rand() / (RAND_MAX), (int)((float)rand() / RAND_MAX * 3));
		for (int i = 0; i < 25; i++) {
			CreatureManager::createCreature(_creatureVector, _speciesVector[y], (float)rand() / RAND_MAX * width, (float)rand() / RAND_MAX * height);
		}
	}
}

void World::drawWorld(sf::RenderWindow& window) {
	sf::Sprite sprite(_backGround.getTexture());
	window.draw(sprite);
	CreatureManager::drawVegetables(window, _gridSize, _vegetableVector, _width, _height);
	CreatureManager::drawCreatures(window, _gridSize, _creatureVector, _width , _height);
}
void World::simulateWorld(sf::RenderWindow& window) {
	CreatureManager::moveAllCreature(_creatureVector, _vegetableVector, _width, _height, _worldMap, _temperatureMap, _gridSize);
	
}



