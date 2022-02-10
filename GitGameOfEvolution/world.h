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
	std::vector<std::vector<float>> _world;
	int _width;
	int _height;
	int _gridSize;
	std::vector<Creature> _creatureVector;
};	

	