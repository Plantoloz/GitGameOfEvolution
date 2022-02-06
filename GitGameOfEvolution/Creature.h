#pragma once

#include <SFML/Graphics.hpp>

class Creature
{
public:
	Creature(float posX, float posY, float strength, float speed, sf::Color color);
	float strength;
	float speed;
	float hunger = 1;
	float posX;
	float posY;
	sf::Color color;
private:
	
};

