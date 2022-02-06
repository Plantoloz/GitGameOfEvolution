#include <SFML/Graphics.hpp>
#include <iostream>

#include "Creature.h"
class CreatureManager
{
public:
	void static drawCreatures(sf::RenderWindow& window, int gridSize, std::vector<Creature>& creatureVector, int width, int height);
private:
	sf::RectangleShape static drawCreature(float size, float x, float y, sf::Color color);
};
