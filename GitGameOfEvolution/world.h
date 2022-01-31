#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "NoiseMap.h"

class World
{
public: 
	void drawWorld(sf::RenderWindow&);
	World(int width, int height,int gridSize);
private:
	sf::RectangleShape drawQuad(float size, float x, float y, sf::Color color);
	void drawFromWorld(sf::RenderTexture& texture);
	std::vector<std::vector<float>> world;
	int width;
	int height;
	int gridSize;
	sf::RenderTexture backGround;
};	

	