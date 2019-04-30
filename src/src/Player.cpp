#include "Player.h"

Player::Player()
{
    //ctor
    m_PlayerShape.setFillColor(sf::Color::Blue);

    for (int i = 0; i < 10; i++)
    {
        BulletCount.push_back(Bullets());
        WindCount.push_back(Bullets());
    }
}

Player::~Player()
{
    //dtor
}

void Player::Render(sf::RenderWindow& window)
{
    window.draw(m_PlayerShape);

    for (int i = 0; i < CurrentAmmo; i++)
    {
        BulletCount[i].Render(window);
    }

     for (int j = 0; j < WindPower; j++)
    {
        WindCount[j].Render(window);
    }
}

void Player::collision()
{
    sf::FloatRect boundingBox = m_PlayerShape.getGlobalBounds();
    m_PlayerShape.getPosition();
}

void Player::Movement()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        m_PlayerShape.move(0.0f, -5.0f);
//     std::cout << "Up" << std::endl;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        m_PlayerShape.move(0.0f, 5.0f);
//       std::cout << "Down" << std::endl;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        m_PlayerShape.move(-5.0f, 0.0f);
        //     std::cout << "Left" << std::endl;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        m_PlayerShape.move(5.0f, 0.0f);
        //      std::cout << "Right" << std::endl;
    }

    PlayerPos = m_PlayerShape.getPosition(); //gets the positonal coords of the player
}

void Player::Shoot(sf::RenderWindow& window)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        sf::Vector2f PlayerMousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window)); //gets the position of the mouse
        BulletCount.push_back(Bullets());
        CurrentAmmo +=1; //increases the number of bullets on screen
        BulletCount[CurrentAmmo].Shooting(PlayerPos, PlayerMousePos); //calls the function from the bullets class

    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
    {
        WindCount.push_back(Bullets());
        WindPower +=1;
        WindCount[WindPower].Wind();
    }
}
void Player::Update()
{
    for (int i = 0; i <= CurrentAmmo; i++)
    {
        if(BulletCount[i].BulletAlive == true)
        {
            BulletCount[i].Update();
        }
    }

    for (int j = 0; j <= WindPower; j++)
    {
        if(WindCount[j].WindActive == true)
        {
            WindCount[j].WindUpdate();
        }
    }
}
