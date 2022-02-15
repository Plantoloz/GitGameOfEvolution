#include <SFML/Graphics.hpp>
#include <iostream>

#include "Creature.h"
class CreatureManager
{
public:
	void static drawCreatures(sf::RenderWindow& window, int gridSize, std::vector<Creature>& creatureVector, int width, int height);
	void static createCreature(std::vector<Creature>& creatureVector, float x, float y, sf::Color color);
	void static createCreatureByBlueprint(std::vector<Creature>& creatureVector, Creature creature);
	void static moveAllCreature(std::vector<Creature>& creatureVector);
private:
	sf::RectangleShape static drawCreature(float size, float x, float y, sf::Color color);
	void static removeCreature(std::vector<Creature>& creatureVector, int index);
	void static killCreature(std::vector<Creature>& creatureVector, int indexKiller, int indexToKill);
};
