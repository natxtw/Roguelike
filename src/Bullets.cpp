#include "Bullets.h"

Bullets::Bullets()
{
    //ctor
    BulletSprite.setPosition(-100, -100);
}

Bullets::~Bullets()
{
    //dtor
}

void Bullets::Shooting(sf::Vector2f BulletSpawnPos, sf::Vector2f MousePos)
{
    BulletPos = sf::Vector2f(BulletSpawnPos.x, BulletSpawnPos.y); //Gathers the bullets X and Y pos
    BulletSprite.setPosition(BulletPos); //sets the sprites position
    float BulletAngleCalculation = atan2(MousePos.y - BulletPos.y, MousePos.x - BulletPos.x); //calculates the angle the bullet is being shot at
    BulletAngle = BulletAngleCalculation; // try removing bulletangle
    BulletAlive = true;
}

void Bullets::Update()
{
    BulletSprite.move(cos(BulletAngle) * 30.0f, 0); //Bullet X coord speed
    BulletSprite.move(0, sin(BulletAngle) * 30.0f); //Bullet Y coord speed
}

void Bullets::Render(sf::RenderWindow& window)
{
    window.draw(BulletSprite);
}
