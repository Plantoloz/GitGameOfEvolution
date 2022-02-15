#include "Creature.h"
Creature::Creature(float size, float posX, float posY, sf::Color color) {
	this->PosX = posX;
	this->PosY = posY;
	this->Color = color;
	this->Size = size;
}

void Creature::move(float amountX, float amountY) {
	this->PosX += amountX;
	this->PosY += amountY;
}