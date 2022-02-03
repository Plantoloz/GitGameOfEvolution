#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Simulator
{
public:
	static void drawWorld(sf::RenderWindow& window, int gridSize, sf::RenderTexture& backGround,
		 std::vector<std::vector<float>>& world);
private:
	static sf::RectangleShape drawQuad(float size, float x, float y, sf::Color color);
	static void drawFromWorld(sf::RenderTexture& texture, std::vector<std::vector<float>>& world, int gridSize);
};

