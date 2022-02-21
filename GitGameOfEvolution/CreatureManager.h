#include <SFML/Graphics.hpp>
#include <iostream>

#include "Creature.h"
#include "Species.h"
#include "Vegetable.h"

class CreatureManager
{
public:
	void static drawCreatures(sf::RenderWindow& window, int gridSize, std::vector<Creature>& creatureVector, int width, int height);
	void static drawVegetables(sf::RenderWindow& window, int gridSize, std::vector<Vegetable>& vegetableVector, int width, int height);
	void static createSpecies(std::vector<Species>& speciesVector, sf::Color color, float size, int number, float favTemp, float favElev, int vore);
	void static createCreature(std::vector<Creature>& creatureVector, Species& specie, float x, float y);
	void static moveAllCreature(std::vector<Creature>& creatureVector, std::vector<Vegetable>& vegetableVector, int width, int height, std::vector<std::vector<float>>& worldMap, std::vector<std::vector<float>>& temperatureMap, int gridSize);
private:
	sf::RectangleShape static drawCreature(float size, float x, float y, sf::Color color);
	void static removeCreature(std::vector<Creature>& creatureVector, int& index);
	void static removeVegetable(std::vector<Vegetable>& vegetableVector, int& index);
	void static interactCreature(std::vector<Creature>& creatureVector, int& indexKiller, int& indexToKill);
};
