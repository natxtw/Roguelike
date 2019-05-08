#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Item.h"
#include "Player.h"
#include "Bullets.h"
#include "AI.h"

#include "Queue.h"
#include "Receiver.h"
#include <thread>


class Game
{
    public:
        Game();
        virtual ~Game();

    void run();
    class Item Collectable;

    void Unpack(std::string& UnpackString);
    std::string Pack();

    protected:

    private:
    int ScreenWidth{1280};
    int ScreenHeight{1024};
    sf::RenderWindow window;
    int amountOfJuice{7};
    int amountOfEnemies{11};
    std::vector<Item> Items;
    std::vector<AI> Enemies;
    bool itemCollision{false};
    bool EnemyCollision{false};
    int Score{0};

};

#endif // GAME_H