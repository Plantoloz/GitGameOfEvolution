
#include "CreatureManager.h"

#pragma region Drawing
void CreatureManager::drawVegetables(sf::RenderWindow& window, int gridSize, std::vector<Vegetable>& vegetableVector, int width, int height) {
	// Base texture to draw all Creatures
	sf::RenderTexture drawnCreature;
	drawnCreature.create(width, height);

	for (int i = 0; i < vegetableVector.size(); i++)
	{
		drawnCreature.draw(drawCreature(vegetableVector[i].FoodValue*10, vegetableVector[i].PosX, vegetableVector[i].PosY, sf::Color(0,255,0) ));
	}

	// Convert
	const sf::Texture& texture = drawnCreature.getTexture();
	// draw it to the window
	sf::Sprite sprite(texture);
	window.draw(sprite);
}

void CreatureManager::drawCreatures(sf::RenderWindow& window, int gridSize, std::vector<Creature>& creatureVector, int width, int height) {
	// Base texture to draw all Creatures
	sf::RenderTexture drawnCreature;
	drawnCreature.create(width, height);

	for (int i = 0; i < creatureVector.size(); i++)
	{
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
	rect.setPosition(sf::Vector2f(x-size/2, y-size / 2));
	return rect;
}

#pragma endregion Drawing

#pragma region InfluenceCreature

void CreatureManager::moveAllCreature(std::vector<Creature>& creatureVector, std::vector<Vegetable>& vegetableVector, int width, int height, std::vector<std::vector<float>> worldMap, std::vector<std::vector<float>> temperatureMap, int gridSize) {
	float dt = 1;
	float moveAmount = 5;

	#pragma region ManagePlants
	// Spawn some plants
	for (int i = 0; i < 3; i++)
	{
		vegetableVector.push_back(Vegetable(1, (float)rand() / RAND_MAX * width, (float)rand() / RAND_MAX * height));
	}
	for (int i = 0; i < vegetableVector.size(); i++)
	{
		vegetableVector[i].FoodValue -= 0.01;
		if (vegetableVector[i].FoodValue <= 0) {
			removeVegetable(vegetableVector, i);
		}
	}
	#pragma endregion ManagePlants

	for (int i = 0; i < creatureVector.size(); i++) {
		int coordX = (int)((int)creatureVector[i].PosX / gridSize);
		if (coordX == width / gridSize) { coordX--; }
		int coordY = (int)((int)creatureVector[i].PosY / gridSize);
		if (coordY == height / gridSize) { coordY--; }
		// Search for food & Best living Area
		float moveX = ((float)rand() / RAND_MAX * 2 - 1) ;
		float moveY = ((float)rand() / RAND_MAX * 2 - 1) ;
		//std::cout << sin(degree * 3.14159 / 180) << std::endl;
		

		// Move
		creatureVector[i].move(moveX * dt * moveAmount, moveY * dt * moveAmount);

		// Spawn Offspring

		// Check Values if still on Map
		if (creatureVector[i].PosX > width) {
			creatureVector[i].PosX = width;
		}
		if (creatureVector[i].PosY > height) {
			creatureVector[i].PosY = height;
		}
		if (creatureVector[i].PosX < 0) {
			creatureVector[i].PosX = 0;
		}
		if (creatureVector[i].PosY < 0) {
			creatureVector[i].PosY = 0;
		}

		// Use Hunger
		float discr = 0.3;
		if (creatureVector[i].Specie.FavTemp > temperatureMap[coordX][coordY] + discr || creatureVector[i].Specie.FavTemp < temperatureMap[coordX][coordY] - discr) {
			creatureVector[i].Hunger -= 0.001 * dt;
		}
		if (creatureVector[i].Specie.FavElev > worldMap[coordX][coordY] + discr || creatureVector[i].Specie.FavElev < worldMap[coordX][coordY] - discr) {
			creatureVector[i].Hunger -= 0.01 * dt;
		}
		if (creatureVector[i].Hunger <= 0) {
			removeCreature(creatureVector, i);
		}
	}

	// Check for Hitbox
	for (int j = 0; j < creatureVector.size(); j++) {
		Creature& cre1 = creatureVector[j];
		for (int y = j+1; y < creatureVector.size(); y++) {
			Creature& cre2 = creatureVector[y];
			float x1 = cre1.PosX;
			float y1 = cre1.PosY;
			float x2 = cre2.PosX;
			float y2 = cre2.PosY;
			// Circle tracking
			// if (pow(pow(x1 - x2, 2) + pow(y1 - y2, 2), 0.5) <= (cre1.Size + cre2.Size) / 2) {

			// Cube traching
			if (abs(x1 - x2) <= cre1.Size / 2 + cre2.Size / 2 && abs(y1 - y2) <= cre1.Size / 2 + cre2.Size / 2){
				// Changes vector and y
				interactCreature(creatureVector, j, y);
				
			}
		}
	}
	
}

void CreatureManager::createSpecies(std::vector<Species>& speciesVector, sf::Color color, float size, int number, float favTemp, float favElev, int vore) {
	speciesVector.push_back(Species(size, color, number, favTemp, favElev, vore));
}

void CreatureManager::createCreature(std::vector<Creature>& creatureVector, Species& specie, float x, float y) {
	creatureVector.push_back(Creature(specie, x, y));
}

void CreatureManager::removeVegetable(std::vector<Vegetable>& vegetableVector, int index) {
	vegetableVector.erase(vegetableVector.begin() + index);
}

void CreatureManager::removeCreature(std::vector<Creature>& creatureVector, int index) {
	creatureVector.erase(creatureVector.begin() + index);
}

// Changes vector!
void CreatureManager::interactCreature(std::vector<Creature>& creatureVector, int indexKiller, int& indexToKill ) {
	//std::cout << creatureVector[indexKiller].Specie.Number << creatureVector[indexToKill].Specie.Number << std::endl;
	if (creatureVector[indexKiller].Specie.Number != creatureVector[indexToKill].Specie.Number) {
		if (creatureVector[indexKiller].Specie.Vore >= 2) {

		}



		//createCreature(creatureVector, creatureVector[indexKiller].Specie, creatureVector[indexToKill].PosX + (float)rand() / RAND_MAX * 2 - 1, creatureVector[indexToKill].PosY + (float)rand() / RAND_MAX * 2 - 1);
		//removeCreature(creatureVector, indexToKill);
		// Exception, adjust to the changing vector
		indexToKill -= 1;
	}
}

#pragma endregion InfluenceCreature