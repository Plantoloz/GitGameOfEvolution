#include "MapCreator.h"

void MapCreator::drawMap(sf::RenderTexture& backGround, int gridSize, std::vector<std::vector<float>>& world) {
	backGround.create(world.size() * gridSize, world[0].size()*gridSize);
	drawFromMap(backGround, world, gridSize);
}


//Drawing every Tile with a color 
void MapCreator::drawFromMap(sf::RenderTexture& texture, std::vector<std::vector<float>>& world, int gridSize) {
	for (int x = 0; x < world.size(); x++)
	{
		for (int y = 0; y < world[y].size(); y++)
		{
			float value = world[x][y];
			sf::Color color;
			// Mountain
			if (value >= 0.9f) {
				color = sf::Color(255, 255, 255);
			}
			else if (value >= 0.85f) {
				color = sf::Color(140, 142, 123);
			}
			else if (value >= 0.8f) {
				color = sf::Color(151, 153, 134);
			}
			// Grass
			else if (value >= 0.7f) {
				color = sf::Color(69, 106, 29);
			}
			else if (value >= 0.5f) {
				color = sf::Color(55, 95, 17);
			}
			//Beach
			else if (value >= 0.4f) {
				color = sf::Color(164, 148, 99);
			}
			else if (value >= 0.35f) {
				color = sf::Color(194, 178, 129);
			}
			// Water
			else if (value >= 0.3f) {
				color = sf::Color(9, 82, 198);
			}
			else if (value >= 0.0f) {
				color = sf::Color(0, 62, 178);
			}
			texture.draw(drawQuad(gridSize, x * gridSize, y * gridSize, color));
		}
	}
}

sf::RectangleShape MapCreator::drawQuad(float size, float x, float y, sf::Color color) {
	sf::RectangleShape rect(sf::Vector2f(size, size));
	rect.setFillColor(color);
	rect.setPosition(sf::Vector2f(x, y));
	return rect;
}