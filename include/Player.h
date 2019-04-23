#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <Bullets.h>

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

        class Bullets bullet;


    protected:

    private:
//        int Healt;
        int CurrentAmmo{0};
        std::vector<Bullets> BulletCount;

};

#endif // PLAYER_H
