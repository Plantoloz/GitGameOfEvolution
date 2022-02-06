#include "Creature.h"
Creature::Creature(float posX, float posY, float strength, float speed, sf::Color color) {
	this->strength = strength;
	this->speed = speed;
	this->posX = posX;
	this->posY = posY;
	this->color = color;
}