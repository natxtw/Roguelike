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
        sf::CircleShape BulletSprite{10.f};
        sf::Vector2f BulletPos;
        float BulletAngle;


        void Wind();
        void WindUpdate();
        float WindAngle;
        bool WindActive{false};
        sf::CircleShape WindSprite{5.f};
        sf::Vector2f WindPos;


    protected:

    private:
    sf::Vector2f WindSpawnPos0{100,100};
    sf::Vector2f WindSpawnPos1{100,200};
    sf::Vector2f WindSpawnPos2{100,300};
    sf::Vector2f WindSpawnPos3{100,400};
    sf::Vector2f WindSpawnPos4{100,500};
    sf::Vector2f WindSpawnPos5{100,600};
    sf::Vector2f WindSpawnPos6{100,700};
    sf::Vector2f WindSpawnPos7{100,800};
    sf::Vector2f WindSpawnPos8{100,900};
    sf::Vector2f WindSpawnPos9{100,1000};
    sf::Vector2f WindSpawnPos10{100,1100};
    sf::Vector2f WindSpawnPos11{100,1200};
};

#endif // BULLETS_H
