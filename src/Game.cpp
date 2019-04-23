#include "Game.h"


Game::Game(): window(sf::VideoMode(ScreenWidth, ScreenHeight), "Nathan Taylor (T7091066) C++ Roguelike Project")
{
    //ctor
    for (int i = 0; i < amountOfJuice; i++)
    {
        Items.push_back(Item());
    }

}

Game::~Game()
{
    //dtor
}

void Game::run()
{

    Player player1;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        player1.Update();
        player1.Movement();
        player1.Shoot(window);

        for (int i = 0; i < amountOfJuice; i++)
        {
            if(Items[i].Alive == false)
            {
                Items[i].isActive();
            }
            if(Items[i].Alive == true)
            {
                Items[i].RenderItem(window);
            }
            itemCollision = (player1.m_PlayerShape.getGlobalBounds().intersects(Items[i].m_ItemJuice.getGlobalBounds()));
            if(itemCollision == true)
            {
                Items[i].Alive = false;
            }
        }

        player1.Render(window);
        window.display();
        window.clear();
    }
}
