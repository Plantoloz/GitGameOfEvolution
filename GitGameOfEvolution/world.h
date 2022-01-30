#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "NoiseMap.h"

class World
{
public: 
	void drawWorld(sf::RenderWindow&);
	World(int, int);
private:
	sf::RectangleShape drawQuad(float size, float y, float x, float color);
	void drawFromWorld(sf::RenderTexture& texture);
	std::vector<std::vector<float>> world;
	int width;
	int height;
	const float gridSize = 10;
	sf::RenderTexture backGround;
};	

	