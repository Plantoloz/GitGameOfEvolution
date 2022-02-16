#include <SFML/Graphics.hpp>
#include <iostream>

#include "Creature.h"
#include "Species.h"

class CreatureManager
{
public:
	void static drawCreatures(sf::RenderWindow& window, int gridSize, std::vector<Creature>& creatureVector, int width, int height);
	void static createSpecies(std::vector<Species>& speciesVector, sf::Color color, float size);
	void static createCreature(std::vector<Creature>& creatureVector, Species specie, float x, float y);
	void static moveAllCreature(std::vector<Creature>& creatureVector);
private:
	sf::RectangleShape static drawCreature(float size, float x, float y, sf::Color color);
	void static removeCreature(std::vector<Creature>& creatureVector, int index);
	void static attackCreature(std::vector<Creature>& creatureVector, int indexKiller, int indexToKill);
};
