#pragma once

#include <SFML/Graphics.hpp>

class Creature
{
public:
	Creature(float size, float posX, float posY, sf::Color color);
	void move(float amountX, float amountY);
	//float Strength;
	//float Speed;
	float Hunger = 1;
	float PosX;
	float PosY;
	float Size;
	sf::Color Color;
private:
	
};

