#include "World.h"

World::World(int width, int height) {
	this->height = height;
	this->width = width;
	this->world = std::vector<std::vector<float>>((int)(width/gridSize), std::vector<float>((int)(height/gridSize)));
	this->world = NoiseMap::createNoiseMap(world);

	this->backGround.create(width, height);

	drawFromWorld(this->backGround);
	
}

void World::drawWorld(sf::RenderWindow &window) {
	const sf::Texture& texture = backGround.getTexture();

	// draw it to the window
	sf::Sprite sprite(texture);
	window.draw(sprite);
}

void World::drawFromWorld(sf::RenderTexture &texture) {
	for (int y = 0; y < world.size(); y++)
	{
		for (int x = 0; x < world[y].size(); x++)
		{
			texture.draw(drawQuad(gridSize, y * gridSize, x * gridSize, world[y][x]));
		}
	}
}

sf::RectangleShape World::drawQuad(float size, float y, float x, float color) {
	sf::RectangleShape rect(sf::Vector2f(size, size));
	rect.setFillColor(sf::Color(0, sf::Uint8(255*color), 0));
	rect.setPosition(sf::Vector2f(y, x));
	return rect;
}