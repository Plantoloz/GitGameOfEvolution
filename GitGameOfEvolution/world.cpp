#include "World.h"

World::World(int width, int height, int gridSize) {
	this->_height = height;
	this->_width = width;
	this->_gridSize = gridSize;
	this->_world = std::vector<std::vector<float>>((int)(width/gridSize), std::vector<float>((int)(height/gridSize)));
	this->_world = NoiseMap::createNoiseMap(_world);
	
	
}

void World::drawWorld(sf::RenderWindow& window) {
	MapCreator::drawMap(window, _gridSize, _world);
	CreatureManager::drawCreatures(window, _gridSize, _creatureVector, _width , _height);
}



