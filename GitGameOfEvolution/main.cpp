#include <SFML/Graphics.hpp>
#include <iostream>
#include "World.h"

int main()
{
    int winHeight = 9*120;
    int winWidth = 16*120;
    int gridSize = 15;
    sf::Clock deltaClock;
    int deltaTime = 0;
    srand((unsigned int)time(NULL));
    sf::RenderWindow window(sf::VideoMode(winWidth, winHeight), "GameOfEvolution, also try GameOfLife", sf::Style::Close | sf::Style::Fullscreen);
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
        int framesPerTick = 30;
        if (deltaTime >= 1000 / framesPerTick) {
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