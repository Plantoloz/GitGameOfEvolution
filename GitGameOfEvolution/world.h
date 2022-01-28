#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "NoiseMap.h"

class World
{
public: 
	void drawWorld(sf::RenderWindow&);
	World(float, float);
private:
	sf::RectangleShape drawQuad(float size, float y, float x, float color);
	void drawFromWorld(sf::RenderWindow& window);
	std::vector<std::vector<float>> world;
	float width;
	float height;
	const int gridSize = 20;
};	

	