#include "MapCreator.h"

void MapCreator::drawMap(sf::RenderTexture& backGround, int gridSize, std::vector<std::vector<float>>& worldMap, std::vector<std::vector<float>>& temperatureMap) {
	backGround.create(worldMap.size() * gridSize, worldMap[0].size()*gridSize);
	drawFromMap(backGround, worldMap, temperatureMap, gridSize);
}


//Drawing every Tile with a color 
void MapCreator::drawFromMap(sf::RenderTexture& texture, std::vector<std::vector<float>>& worldMap, std::vector<std::vector<float>>& temperatureMap, int gridSize) {
	for (int x = 0; x < worldMap.size(); x++)
	{
		for (int y = 0; y < worldMap[y].size(); y++)
		{
			float value = worldMap[x][y];
			float tmp = 
				(temperatureMap[x][y]*60-30);
			sf::Color color;
			// Mountain
			if (value >= 0.9f) {
				if (tmp <= 0) {
					tmp = 0;
				}
				color = sf::Color(255-tmp, 255, 255);
			}
			else if (value >= 0.85f) {
				color = sf::Color(140-tmp, 142, 123);
			}
			else if (value >= 0.8f) {
				color = sf::Color(151-tmp, 153, 134);
			}
			// Grass
			else if (value >= 0.7f) {
				color = sf::Color(69-tmp, 106, 29);
			}
			else if (value >= 0.5f) {
				color = sf::Color(55-tmp, 95, 17);
			}
			//Beach
			else if (value >= 0.4f) {
				color = sf::Color(164 - tmp, 148, 99);
			}
			else if (value >= 0.35f) {
				color = sf::Color(194 - tmp, 178, 129);
			}
			// Water
			else if (value >= 0.2f) {
				if (tmp >= 9) {
					tmp = 9;
				}
				color = sf::Color(9 - tmp, 82, 198);
			}
			else if (value >= 0.0f) {
				if (tmp >= 0) {
					tmp = 0;
				}
				color = sf::Color(0 - tmp, 62, 178);
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