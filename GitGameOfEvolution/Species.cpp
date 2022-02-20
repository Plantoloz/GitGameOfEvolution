#include "Species.h"

Species::Species(float size, sf::Color color, int number, float favTemp, float favElev, int vore) {
	this->Size = size;
	this->Color = color;
	this->Number = number;
	this->FavTemp = favTemp;
	this->FavElev = favElev;
	this->Vore = vore;
}