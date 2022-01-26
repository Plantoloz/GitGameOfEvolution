#include "World.h"


World::World(int width, int height) {
	this->world = std::vector<std::vector<int>>(width, std::vector<int>(height));
}