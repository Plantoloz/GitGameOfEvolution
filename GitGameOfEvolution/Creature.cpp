#include "Creature.h"
Creature::Creature(Species& species, float x, float y) : Specie(species) {
	//this->Color = species.Color;
	//this->Size = species.Size;
	this->PosX = x;
	this->PosY = y;
}

void Creature::move(float amountX, float amountY) {
	this->PosX += amountX;
	this->PosY += amountY;
}