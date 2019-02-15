#include "Game.h"
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Item.h"

Game::Game(): window(sf::VideoMode(ScreenWidth, ScreenHeight), "Wait What! Something Nathan Compiled Worked??")
{
    //ctor
}

Game::~Game()
{
    //dtor
}

void Game::run()
{

    Player player1;
    Item Juice;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

                player1.Movement();
        }

        window.clear();
        player1.Render(window);
        Juice.RenderItem(window);
        window.display();
    }
}
