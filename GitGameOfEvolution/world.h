#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "NoiseMap.h"
#include "MapCreator.h"
#include "CreatureManager.h"
#include "Creature.h"
class World
{
public: 
	World(int width, int height,int gridSize);
	void drawWorld(sf::RenderWindow& window);
private:
	std::vector<std::vector<float>> world;
	int width;
	int height;
	int gridSize;
	sf::RenderTexture backGround;
	std::vector<Creature> creatureVector;
};	

	