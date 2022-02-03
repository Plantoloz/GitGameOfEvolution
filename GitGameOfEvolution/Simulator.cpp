#include "Simulator.h"

void Simulator::drawWorld(sf::RenderWindow& window, int gridSize, sf::RenderTexture& backGround, std::vector<std::vector<float>>& world) {
	drawFromWorld(backGround, world, gridSize);
	const sf::Texture& texture = backGround.getTexture();

	// draw it to the window
	sf::Sprite sprite(texture);
	window.draw(sprite);
}

void Simulator::drawFromWorld(sf::RenderTexture& texture, std::vector<std::vector<float>>& world, int gridSize) {
	for (int x = 0; x < world.size(); x++)
	{
		for (int y = 0; y < world[y].size(); y++)
		{
			float value = world[x][y];
			sf::Color color;
			if (value >= 0.8f) {
				color = sf::Color(value * 255.0f * 1.0f, value * 255.0f * 0.5f, 0);
			}
			else if (value >= 0.3f) {
				color = sf::Color(value * 255.0f * 0.5f, value * 255.0f * 1.0f, 0);
			}
			else if (value >= 0.0f) {
				color = sf::Color(0, value * 255.0f * 0.5f, value * 255.0f * 1.0f);
			}

			texture.draw(drawQuad(gridSize, x * gridSize, y * gridSize, color));
		}
	}
}

sf::RectangleShape Simulator::drawQuad(float size, float x, float y, sf::Color color) {
	sf::RectangleShape rect(sf::Vector2f(size, size));
	rect.setFillColor(color);
	rect.setPosition(sf::Vector2f(x, y));
	return rect;
}