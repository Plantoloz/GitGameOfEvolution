#include "World.h"

World::World(int width, int height, int gridSize) {
	this->_height = height;
	this->_width = width;
	this->_gridSize = gridSize;
	this->_world = std::vector<std::vector<float>>((int)(width/gridSize), std::vector<float>((int)(height/gridSize)));
	this->_world = NoiseMap::createNoiseMap(_world);
	MapCreator::drawMap(backGround, _gridSize, _world);

	srand((unsigned int)time(NULL));
	for (int i = 0; i < 100; i++) {
		CreatureManager::createCreature(_creatureVector, (float)rand() / RAND_MAX * width, (float)rand() / RAND_MAX * height, sf::Color(255, 1, 1));
	}
}

void World::drawWorld(sf::RenderWindow& window) {
	sf::Sprite sprite(backGround.getTexture());
	window.draw(sprite);

	CreatureManager::drawCreatures(window, _gridSize, _creatureVector, _width , _height);
}



