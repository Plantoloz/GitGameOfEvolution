#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Species
{
public:
	Species(float size, sf::Color color, int number, float favTemp, float favElev, int vore);
	float Size; // Size of Base Creature 
	sf::Color Color; 
	int Number; // SpeciesIndex
	float FavTemp; // Temperature 0 - 1
	float FavElev; // Elevation 0 - 1
	int Vore; // 0 Herbivore, 1 Carnivore, 2 Omnivore
};
