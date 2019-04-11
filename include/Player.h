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
        void collision();

        int m_PlayersXPos;
        int m_PlayersYPos;
        sf::CircleShape m_PlayerShape{80.f};
        void Render(sf::RenderWindow& window);

    protected:

    private:

};

#endif // PLAYER_H
