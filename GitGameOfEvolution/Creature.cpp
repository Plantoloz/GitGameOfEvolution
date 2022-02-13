#include "Creature.h"
Creature::Creature(float posX, float posY, sf::Color color) {
	this->PosX = posX;
	this->PosY = posY;
	this->Color = color;
}

void Creature::move(float amountX, float amountY) {
	this->PosX += amountX;
	this->PosY += amountY;
}