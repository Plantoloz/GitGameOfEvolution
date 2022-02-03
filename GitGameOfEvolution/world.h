#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "NoiseMap.h"
#include "Simulator.h"

class World
{
public: 
	World(int width, int height,int gridSize);
	void simulateWorld(sf::RenderWindow& window);
private:
	std::vector<std::vector<float>> world;
	int width;
	int height;
	int gridSize;
	sf::RenderTexture backGround;
};	

	