#include <SFML/Graphics.hpp>
#include <iostream>
#include "World.h"

int main()
{
    int winHeight = 9*60;
    int winLenght = 16*60;
    sf::RenderWindow window(sf::VideoMode(winLenght, winHeight), "SFML works!", sf::Style::Close | sf::Style::Resize);
    World world(winLenght, winHeight);

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
                std::cout << "Height: " << event1.size.height << " Width: " << event1.size.width << std::endl;
                break;
            case sf::Event::TextEntered:
                if (event1.text.unicode < 128) {
                    printf("%c", event1.text.unicode);
                }
                break;
            }

        }

        window.clear();

        // Function to Generate World. A Class to simulate the simulation
        
        // Function to Display World
        world.drawWorld(window);
        

        window.display();
    }

    return 0;
}