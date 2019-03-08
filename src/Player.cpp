#include "Player.h"

Player::Player()
{
    //ctor
    m_PlayerShape.setFillColor(sf::Color::Blue);
}

Player::~Player()
{
    //dtor
}

void Player::Render(sf::RenderWindow& window)
{
    window.draw(m_PlayerShape);
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
}
