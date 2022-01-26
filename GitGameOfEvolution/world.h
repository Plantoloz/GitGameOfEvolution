#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


class World
{
public: 
	World(int, int);
	void drawWindow(sf::RenderWindow&);
private:
	std::vector<std::vector<int>> world;
	int width;
	int height;
};	

	