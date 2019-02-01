#include "Game.h"
#include <SFML/Graphics.hpp>

Game::Game()
{
    //ctor
}

Game::~Game()
{
    //dtor
}

void Game::run()
{
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Blue);

    sf::RenderWindow window(sf::VideoMode(1280, 1024), "SFML works!");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
}
