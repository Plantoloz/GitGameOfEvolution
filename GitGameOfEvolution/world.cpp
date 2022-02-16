#include "World.h"

World::World(int width, int height, int gridSize) {
	this->_height = height;
	this->_width = width;
	this->_gridSize = gridSize;
	this->_world = std::vector<std::vector<float>>((int)(width/gridSize), std::vector<float>((int)(height/gridSize)));
	this->_world = NoiseMap::createNoiseMap(_world);
	MapCreator::drawMap(_backGround, _gridSize, _world);

	for (int i = 0; i < 100; i++) {
		CreatureManager::createCreature(_creatureVector, (float)rand() / RAND_MAX * width, (float)rand() / RAND_MAX * height, sf::Color(rand(), rand(), rand()));
	}
}

void World::drawWorld(sf::RenderWindow& window) {
	CreatureManager::moveAllCreature(_creatureVector);
	sf::Sprite sprite(_backGround.getTexture());
	window.draw(sprite);
	CreatureManager::drawCreatures(window, _gridSize, _creatureVector, _width , _height);
}



