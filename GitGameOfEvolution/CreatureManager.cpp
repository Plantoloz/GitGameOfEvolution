
#include "CreatureManager.h"

#pragma region Drawing
void CreatureManager::drawCreatures(sf::RenderWindow& window, int gridSize, std::vector<Creature>& creatureVector, int width, int height) {
	// Base texture to draw all Creatures
	sf::RenderTexture drawnCreature;
	drawnCreature.create(width, height);

	for (int i = 0; i < creatureVector.size(); i++)
	{
		if (creatureVector[i].PosX > width - creatureVector[i].Size) {
			creatureVector[i].PosX = width - creatureVector[i].Size;
		}
		if (creatureVector[i].PosY > height - creatureVector[i].Size) {
			creatureVector[i].PosY = height - creatureVector[i].Size;
		}
		if (creatureVector[i].PosX < 0) {
			creatureVector[i].PosX = 0;
		}
		if (creatureVector[i].PosY < 0) {
			creatureVector[i].PosY = 0;
		}
		drawnCreature.draw(drawCreature(creatureVector[i].Size, creatureVector[i].PosX, creatureVector[i].PosY, creatureVector[i].Color));
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

void CreatureManager::moveAllCreature(std::vector<Creature>& creatureVector, sf::Time deltaTime) {
	
	for (int i = 0; i < creatureVector.size(); i++) {
		creatureVector[i].move(((float)rand() / RAND_MAX * 2 - 1)*(float)deltaTime.asMilliseconds()/10, ((float)rand() / RAND_MAX * 2 - 1) * (float)deltaTime.asMilliseconds()/10);
	}

	// Check for Hitbox
	for (int j = 0; j < creatureVector.size(); j++) {
		Creature& cre1 = creatureVector[j];
		for (int y = j+1; y < creatureVector.size(); y++) {
			Creature& cre2 = creatureVector[y];
			// Circle tracking
			float x1 = cre1.PosX + cre1.Size / 2;
			float y1 = cre1.PosY + cre1.Size / 2;
			float x2 = cre2.PosX + cre2.Size / 2;
			float y2 = cre2.PosY + cre2.Size / 2;
			if (pow(pow(x1 - x2, 2) + 
					pow(y1 - y2, 2), 0.5) 
					<= (cre1.Size + cre2.Size) / 2) {

				// Changes vector and y
				interactCreature(creatureVector, j, y);
				
			}
		}
	}
	
}

void CreatureManager::createSpecies(std::vector<Species>& speciesVector, sf::Color color, float size, int number) {
	speciesVector.push_back(Species(size, color, number));
}

void CreatureManager::createCreature(std::vector<Creature>& creatureVector, Species& specie, float x, float y) {
	creatureVector.push_back(Creature(specie, x, y));
}

void CreatureManager::removeCreature(std::vector<Creature>& creatureVector, int index) {
	creatureVector.erase(creatureVector.begin() + index);
}

// Changes vector!
void CreatureManager::interactCreature(std::vector<Creature>& creatureVector, int indexKiller, int& indexToKill ) {
	//std::cout << creatureVector[indexKiller].Specie.Number << creatureVector[indexToKill].Specie.Number << std::endl;
	if (creatureVector[indexKiller].Specie.Number != creatureVector[indexToKill].Specie.Number) {
		createCreature(creatureVector, creatureVector[indexKiller].Specie, creatureVector[indexToKill].PosX + (float)rand() / RAND_MAX * 2 - 1, creatureVector[indexToKill].PosY + (float)rand() / RAND_MAX * 2 - 1);
		removeCreature(creatureVector, indexToKill);
		// Exception, adjust to the changing vector
		indexToKill -= 1;
	}
}

#pragma endregion InfluenceCreature