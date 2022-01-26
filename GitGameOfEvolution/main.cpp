#include <SFML/Graphics.hpp>
#include <iostream>

#include "Species.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!", sf::Style::Close | sf::Style::Resize);
    sf::RectangleShape shape(sf::Vector2f(100.f, 100.f));
    shape.setFillColor(sf::Color::Green);

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

        // Function to Generate World
        // Function to Display World

        window.draw(shape);
        

        window.display();
    }

    return 0;
}