#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Item.h"
#include "Player.h"
#include "Bullets.h"


class Game
{
    public:
        Game();
        virtual ~Game();

    void run();
    class Item Collectable;
    protected:

    private:
    int ScreenWidth{1280};
    int ScreenHeight{1024};
    sf::RenderWindow window;
    int amountOfJuice{7};
    std::vector<Item> Items;
    bool itemCollision{false};

};

#endif // GAME_H
