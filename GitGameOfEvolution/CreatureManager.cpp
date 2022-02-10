
#include "CreatureManager.h"

#pragma region Drawing
void CreatureManager::drawCreatures(sf::RenderWindow& window, int gridSize, std::vector<Creature>& creatureVector, int width, int height) {
	// Base texture to draw all Creatures
	sf::RenderTexture drawnCreature;
	drawnCreature.create(width, height);

	for (int i = 0; i < creatureVector.size(); i++)
	{
		drawnCreature.draw(drawCreature(1.5*gridSize, creatureVector[i].PosX, creatureVector[i].PosY, creatureVector[i].Color));
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

void CreatureManager::createCreature(std::vector<Creature>& creatureVector) {
	creatureVector.push_back(Creature(34, 400, sf::Color(1, 1, 1)));
	creatureVector.push_back(Creature(40, 300, sf::Color(255, 1, 1)));
	creatureVector.push_back(Creature(600, 300, sf::Color(1, 1, 255)));
	creatureVector.push_back(Creature(500, 400, sf::Color(1, 125, 1)));
}

void CreatureManager::removeCreature(std::vector<Creature>& creatureVector, int index) {
	creatureVector.erase(creatureVector.begin() + index);
}

#pragma endregion InfluenceCreature