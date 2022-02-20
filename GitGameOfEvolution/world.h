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
	void simulateWorld(sf::RenderWindow& window, sf::Time deltaTime);
private:
	std::vector<std::vector<float>> _worldMap;
	std::vector<std::vector<float>> _temperatureMap;
	int _width;
	int _height;
	int _gridSize;
	std::vector<Creature> _creatureVector;
	std::vector<Species> _speciesVector;
	sf::RenderTexture _backGround;
};	

	