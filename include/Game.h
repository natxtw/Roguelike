#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Item.h"
#include "Player.h"

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
    int amountOfJuice{3};
    std::vector<Item> Items;
    bool itemCollision{false};

};

#endif // GAME_H
