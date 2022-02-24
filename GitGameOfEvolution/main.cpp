#include <SFML/Graphics.hpp>
#include <iostream>
#include "World.h"

int main()
{
    int winHeight = 9*60;
    int winWidth = 16*60;
    int gridSize = 10;
    sf::Clock deltaClock;
    int deltaTime = 0;
    srand((unsigned int)time(NULL));
    sf::RenderWindow window(sf::VideoMode(winWidth, winHeight), "GameOfEvolution, also try GameOfLive", sf::Style::Close | sf::Style::Resize);
    World world(winWidth, winHeight, gridSize);
    window.setFramerateLimit(60);
    while (window.isOpen())
    {
        sf::Event event1;
        while (window.pollEvent(event1))
        {

            switch (event1.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::Resized:
                break;
            case sf::Event::TextEntered:
                if (event1.text.unicode < 128) {
                    printf("%c", event1.text.unicode);
                }
                break;
            }

        }

        window.clear();

        deltaTime += deltaClock.restart().asMilliseconds();
        int framesPerTick = 60;
        if (deltaTime >= 1000/ framesPerTick) {
            deltaTime -= 1000 / framesPerTick;
            world.simulateWorld(window);
        }
        // Simulate 1 Move
        
        
        // Function to Display World
        world.drawWorld(window);

        window.display();

    }

    return 0;
}