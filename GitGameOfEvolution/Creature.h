#pragma once

#include <SFML/Graphics.hpp>

class Creature
{
public:
	Creature(float posX, float posY, sf::Color color);
	float Strength;
	float Speed;
	float Hunger = 1;
	float PosX;
	float PosY;
	sf::Color Color;
private:
	
};

