#include "World.h"


World::World(int width, int height) {
	this->world = std::vector<std::vector<int>>(width, std::vector<int>(height));
}

void World::drawWindow(sf::RenderWindow &window) {
	sf::RectangleShape map(sf::Vector2f(120.f, 50.f));
	window.draw(map);

}