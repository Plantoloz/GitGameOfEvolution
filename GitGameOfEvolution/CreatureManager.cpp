
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

void CreatureManager::moveAllCreature(std::vector<Creature>& creatureVector, std::vector<Vegetable>& vegetableVector, int width, int height, std::vector<std::vector<float>>& worldMap, std::vector<std::vector<float>>& temperatureMap, int gridSize, int deltaTime, int& deltaTimeSum) {
	deltaTimeSum += deltaTime;
	float moveAmount = 5;
	if (deltaTimeSum >= 200) {
		// Spawn some plants
		for (int i = 0; i < 5; i++)
		{
			vegetableVector.push_back(Vegetable(1, (float)rand() / RAND_MAX * width, (float)rand() / RAND_MAX * height));
		}
		deltaTimeSum -= 200;
	}
	#pragma region ManagePlants

	// Implementing Rotting
	for (int i = 0; i < vegetableVector.size(); i++)
	{
		vegetableVector[i].FoodValue -= 0.01*deltaTime;
		if (vegetableVector[i].FoodValue <= 0) {
			removeVegetable(vegetableVector, i);
			continue;
		}
	}
	#pragma endregion ManagePlants
	for (int i = 0; i < creatureVector.size(); i++) {
		// Search for food & Best living Area
		float moveX = ((float)rand() / RAND_MAX * 2 - 1) ;
		float moveY = ((float)rand() / RAND_MAX * 2 - 1) ;
		//std::cout << sin(degree * 3.14159 / 180) << std::endl;
		

		// Move
		creatureVector[i].move(moveX * deltaTime * moveAmount, moveY * deltaTime * moveAmount);


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


		// Spawn Offspring
		if (creatureVector[i].Hunger >= 1.5) {
			createCreature(creatureVector, creatureVector[i].Specie, creatureVector[i].PosX + (float)rand() / RAND_MAX * 2 * 10, creatureVector[i].PosY + (float)rand() / RAND_MAX * 2 * 10);
			
			creatureVector[i].Hunger -= 0.5 * (creatureVector[i].Size/10);
		}
		std::cout << "loop1" << std::endl;
		// Adjust Hunger && Erzeugt gelegentlich out of bounce error. Konnte nicht wieder reproduziert werden
		int coordX = (int)((int)creatureVector[i].PosX / gridSize);
		if (coordX == width / gridSize) { coordX--; }
		int coordY = (int)((int)creatureVector[i].PosY / gridSize);
		if (coordY == height / gridSize) { coordY--; }
		//std::cout << coordX << " X" << temperatureMap.size() << std::endl;
		//std::cout << coordY << " Y" << temperatureMap.size() << std::endl;
		float discr = 0.3;
		std::cout << "loop2" << std::endl;
		if (creatureVector[i].Specie.FavTemp > temperatureMap[coordX][coordY] + discr || creatureVector[i].Specie.FavTemp < temperatureMap[coordX][coordY] - discr) {
			creatureVector[i].Hunger -= 0.001 * deltaTime;
		}
		if (creatureVector[i].Specie.FavElev > worldMap[coordX][coordY] + discr || creatureVector[i].Specie.FavElev < worldMap[coordX][coordY] - discr) {
			creatureVector[i].Hunger -= 0.01 * deltaTime;
		}

		// Kill if no Food
		if (creatureVector[i].Hunger <= 0) {
			removeCreature(creatureVector, i);
			continue;
		}
	}
	std::cout << "loop3" << std::endl;
	// Check for Hitbox
	for (int j = 0; j < creatureVector.size(); j++) {
		// Creatures
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
				continue;
			}
		}
		// Vegetable
		for (int i = j+1; i < vegetableVector.size(); i++)
		{
			Vegetable& veg2 = vegetableVector[i];
			float x1 = cre1.PosX;
			float y1 = cre1.PosY;
			float x2 = veg2.PosX;
			float y2 = veg2.PosY;
			if (abs(x1 - x2) <= cre1.Size / 2 + veg2.FoodValue * 10 / 2 && abs(y1 - y2) <= cre1.Size / 2 + veg2.FoodValue * 10 / 2) {
				//std::cout << i << " " << j << " " << vegetableVector.size() << std::endl;
				cre1.Hunger += veg2.FoodValue;
				removeVegetable(vegetableVector, i);
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

void CreatureManager::removeVegetable(std::vector<Vegetable>& vegetableVector, int& index) {
	vegetableVector.erase(vegetableVector.begin() + index);
	index--;
}

void CreatureManager::removeCreature(std::vector<Creature>& creatureVector, int& index) {
	creatureVector.erase(creatureVector.begin() + index);
	index--;
}

// Changes vector!
void CreatureManager::interactCreature(std::vector<Creature>& creatureVector, int& index1, int& index2) {
	//std::cout << creatureVector[indexKiller].Specie.Number << creatureVector[indexToKill].Specie.Number << std::endl;
	if (creatureVector[index1].Specie.Number != creatureVector[index2].Specie.Number) {
		if (creatureVector[index1].Size >= creatureVector[index2].Size) {
			creatureVector[index1].Hunger += creatureVector[index2].Hunger;
			removeCreature(creatureVector, index2);
		}
		else {
			creatureVector[index2].Hunger += creatureVector[index1].Hunger;
			removeCreature(creatureVector, index1);
		}
		// Exception, adjust to the changing vector
	}
}

#pragma endregion InfluenceCreature