#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class MapCreator
{
public:
	static void drawMap(sf::RenderTexture& backGround, int gridSize,
		 std::vector<std::vector<float>>& world);
private:
	static sf::RectangleShape drawQuad(float size, float x, float y, sf::Color color);
	static void drawFromMap(sf::RenderTexture& texture, std::vector<std::vector<float>>& world, int gridSize);

};

