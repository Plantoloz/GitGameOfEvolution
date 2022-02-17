#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Species
{
public:
	Species(float size, sf::Color color, int number);
	float Size;
	sf::Color Color;
	int Number;
};
