#include "World.h"

World::World(float width, float height) {
	this->height = height;
	this->width = width;
	this->world = std::vector<std::vector<float>>((int)width/gridSize, std::vector<float>((int)height/gridSize));
	this->world[10][10] = 1;
	this->world[10][9] = 0.4f;
	this->world[1][1] = 0.9f;
	this->world[0][0] = 1;
	this->world = NoiseMap::createNoiseMap(world);
}

void World::drawWorld(sf::RenderWindow &window) {
	drawFromWorld(window);
}

void World::drawFromWorld(sf::RenderWindow &window) {
	for (float y = 0; y < world.size(); y++)
	{
		for (float x = 0; x < world[y].size(); x++)
		{
			if (world[y][x] > 0.3f) {
				window.draw(drawQuad(gridSize, y * gridSize, x * gridSize, world[y][x]));
			}
		}
	}
}

sf::RectangleShape World::drawQuad(float size, float y, float x, float color) {
	sf::RectangleShape rect(sf::Vector2f(size, size));
	rect.setFillColor(sf::Color(0, sf::Uint8(255*color), 0));
	rect.setPosition(sf::Vector2f(y, x));
	return rect;
}