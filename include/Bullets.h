#ifndef BULLETS_H
#define BULLETS_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Bullets
{
    public:
        Bullets();
        virtual ~Bullets();

        void Shooting(sf::Vector2f BulletSpawnPos, sf::Vector2f Mousepos);
        void Render(sf::RenderWindow& window);
        void Update();
        bool BulletAlive{false};
        //sf::Texture BulletSprite;
        sf::CircleShape BulletSprite{10.f};
        sf::Vector2f BulletPos;
        float BulletAngle;


    protected:

    private:
};

#endif // BULLETS_H
