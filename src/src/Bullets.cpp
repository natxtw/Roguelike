#include "Bullets.h"

Bullets::Bullets()
{
    //ctor
    BulletSprite.setPosition(-100, -100);
    WindSprite.setPosition(-100, -100);
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

void Bullets::WindUpdate()
{
    WindSprite.move(25, 0);
}

void Bullets::Render(sf::RenderWindow& window)
{
    window.draw(BulletSprite);
    window.draw(WindSprite);
}

void Bullets::Wind()
{
    int windl = rand()%11;
    if(windl == 0)
    {
    WindPos = WindSpawnPos0; //Gathers X and Y pos
    }
    if(windl == 1)
    {
    WindPos = WindSpawnPos1; //Gathers X and Y pos
    }
    if(windl == 2)
    {
    WindPos = WindSpawnPos2; //Gathers X and Y pos
    }
    if(windl == 3)
    {
    WindPos = WindSpawnPos3; //Gathers X and Y pos
    }
    if(windl == 4)
    {
    WindPos = WindSpawnPos4; //Gathers X and Y pos
    }
    if(windl == 5)
    {
    WindPos = WindSpawnPos5; //Gathers X and Y pos
    }
    if(windl == 6)
    {
    WindPos = WindSpawnPos6; //Gathers X and Y pos
    }
    if(windl == 7)
    {
    WindPos = WindSpawnPos7; //Gathers X and Y pos
    }
    if(windl == 8)
    {
    WindPos = WindSpawnPos8; //Gathers X and Y pos
    }
    if(windl == 9)
    {
    WindPos = WindSpawnPos9; //Gathers X and Y pos
    }
    if(windl == 10)
    {
    WindPos = WindSpawnPos10; //Gathers X and Y pos
    }
    if(windl == 11)
    {
    WindPos = WindSpawnPos11; //Gathers X and Y pos
    }

    WindSprite.setPosition(WindPos); //sets the sprites position
    float WindAngleCalculation = atan2(0.0 - WindPos.y, -800.0 - WindPos.x); //calculates the angle of the wind
    WindAngle = WindAngleCalculation;
    WindActive = true;
}

