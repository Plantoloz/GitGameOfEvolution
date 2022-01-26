#pragma once
#include <SFML/Graphics.hpp>

#include <iostream>


class World
{
public: 
	World(int, int);
	sf::Window drawWindow(sf::Window);
private:
	std::vector<std::vector<int>> world;
	int width;
	int height;
		
};	

	