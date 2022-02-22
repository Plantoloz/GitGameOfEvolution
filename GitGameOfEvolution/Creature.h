#pragma once

#include <SFML/Graphics.hpp>
#include "Species.h"
class Creature
{
public:
	Creature(Species& species, float x, float y);
	void move(float amountX, float amountY);
	//float Strength;
	//float Speed;
	float Hunger = 0.5;
	float PosX;
	float PosY;
	float Size;
	sf::Color Color;
	Species Specie;
private:
	
};

