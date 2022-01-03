#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!", sf::Style::Close | sf::Style::Resize);
    sf::RectangleShape shape(sf::Vector2f(100.f, 100.f));
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event evnt;
        while (window.pollEvent(evnt))
        {

            switch (evnt.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::Resized:
                std::cout << "Height: " << evnt.size.height << " Width: " << evnt.size.width << std::endl;
                break;
            case sf::Event::TextEntered:
                if (evnt.text.unicode < 128) {
                    printf("%c", evnt.text.unicode);
                }
            }

        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}