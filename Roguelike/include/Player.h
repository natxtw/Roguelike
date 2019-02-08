#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Player
{
    public:
        Player();
        virtual ~Player();
        void Movement();
        void Render(sf::RenderWindow& window);
        void collision();

        int m_PlayersXPos;
        int m_PlayersYPos;

    protected:

    private:
        sf::CircleShape m_PlayerShape{80.f};
};

#endif // PLAYER_H
