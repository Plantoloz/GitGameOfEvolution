
#include "CreatureManager.h"

#pragma region Drawing
void CreatureManager::drawCreatures(sf::RenderWindow& window, int gridSize, std::vector<Creature>& creatureVector, int width, int height) {
	// Base texture to draw all Creatures
	sf::RenderTexture drawnCreature;
	drawnCreature.create(width, height);

	for (int i = 0; i < creatureVector.size(); i++)
	{
		drawnCreature.draw(drawCreature(10, creatureVector[i].PosX, creatureVector[i].PosY, creatureVector[i].Color));
	}
	
	// Convert
	const sf::Texture& texture = drawnCreature.getTexture();
	// draw it to the window
	sf::Sprite sprite(texture);
	window.draw(sprite);
}


sf::RectangleShape CreatureManager::drawCreature(float size, float x, float y, sf::Color color) {
	sf::RectangleShape rect(sf::Vector2f(size, size));
	rect.setFillColor(color);
	rect.setPosition(sf::Vector2f(x, y));
	return rect;
}
#pragma endregion Drawing

#pragma region InfluenceCreature

void CreatureManager::moveAllCreature(std::vector<Creature>& creatureVector) {
	srand((unsigned int)time(NULL));
	
	for (int i = 0; i < creatureVector.size(); i++) {
		creatureVector[i].move(((float)rand() / RAND_MAX * 2 - 1)*1, ((float)rand() / RAND_MAX * 2 - 1) * 1);
	}
}

void CreatureManager::createCreature(std::vector<Creature>& creatureVector, float x, float y, sf::Color color) {
	creatureVector.push_back(Creature(x, y, color));
}

void CreatureManager::createCreatureByBlueprint(std::vector<Creature>& creatureVector, Creature creature) {
	creatureVector.push_back(creature);
}

void CreatureManager::removeCreature(std::vector<Creature>& creatureVector, int index) {
	creatureVector.erase(creatureVector.begin() + index);
}

#pragma endregion InfluenceCreature