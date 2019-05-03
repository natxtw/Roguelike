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
    sf::Vector2f WindSpawnPos0{0,150};
    sf::Vector2f WindSpawnPos1{0,350};
    sf::Vector2f WindSpawnPos2{0,550};
    sf::Vector2f WindSpawnPos3{0,750};
    sf::Vector2f WindSpawnPos4{0,950};
    sf::Vector2f WindSpawnPos5{0,1150};
    sf::Vector2f WindSpawnPos6{0,1350};
//    sf::Vector2f WindSpawnPos7{0,800};
//    sf::Vector2f WindSpawnPos8{0,900};
//    sf::Vector2f WindSpawnPos9{0,1000};
//    sf::Vector2f WindSpawnPos10{0,1100};
//    sf::Vector2f WindSpawnPos11{0,1200};
};

#endif // BULLETS_H
