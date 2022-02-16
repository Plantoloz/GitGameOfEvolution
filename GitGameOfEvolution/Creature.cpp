#include "Creature.h"
Creature::Creature(float size, sf::Color color) {
	this->Color = color;
	this->Size = size;
}

void Creature::move(float amountX, float amountY) {
	this->PosX += amountX;
	this->PosY += amountY;
}