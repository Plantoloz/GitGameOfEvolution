#include "World.h"

World::World(int width, int height, int gridSize) {
	this->height = height;
	this->width = width;
	this->gridSize = gridSize;
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
	for (int x = 0; x < world.size(); x++)
	{
		for (int y = 0; y < world[y].size(); y++)
		{
			float value = world[x][y];
			sf::Color color;
			if (value >= 0.7f) {
				color = sf::Color(value * 255.0f * 0.5f, value * 255.0f * 0.25f, 0);
			}
			else if(value >= 0.3f) {
				color = sf::Color(value * 255.0f * 0.25f, value * 255.0f * 0.5f, 0);
			}
			else if (value >= 0.0f) {
				color = sf::Color(0, value * 255.0f * 0.25f, value*255.0f*0.5f);
			}
			/*
			if (value >= 0.5f) {
				color = sf::Color(255, 255, 255);
			}
			else {
				color = sf::Color(0, 0, 0);
			}
			*/	
			
			texture.draw(drawQuad(gridSize, x * gridSize, y * gridSize, color));		
		}
	}
}

sf::RectangleShape World::drawQuad(float size, float x, float y, sf::Color color) {
	sf::RectangleShape rect(sf::Vector2f(size, size));
	rect.setFillColor(color);
	rect.setPosition(sf::Vector2f(x, y));
	return rect;
}