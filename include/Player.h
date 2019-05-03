#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <Bullets.h>
#include <Game.h>

class Player
{
    public:
        Player();
        virtual ~Player();
        void Movement();
        void collision();

        sf::Vector2f PlayerPos{0.0f, 0.0f};
        sf::CircleShape m_PlayerShape{40.f};

        void Render(sf::RenderWindow& window);
        void Shoot(sf::RenderWindow& window);
        void Update();
        std::vector<Bullets> BulletCount;
        int CurrentAmmo{0};
        std::vector<Bullets> WindCount;
        int WindPower{0};

        class Bullets bullet;
//        class Game game;

        int FireTheAmmo{20};


    protected:

    private:
//      int Healt;


};

#endif // PLAYER_H
