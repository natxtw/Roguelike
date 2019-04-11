#include "Item.h"
#include <iostream>

Item::Item()
{
    //ctor
    m_ItemJuice.setFillColor(sf::Color::Green);
}

Item::~Item()
{
    //dtor
}

void Item::isActive()
{
if(Alive == false)
{
            if((rand()%50) == 0)
            {
                Alive = true;
                float xCoord = rand() % 1280 - 100;
                float yCoord = rand() % 1040 - 100;
                if(xCoord <= 100)
                {
                    xCoord += 100;
                }

                m_pos.x = xCoord;
                m_pos.y = yCoord;

                m_ItemJuice.setPosition(m_pos.x, m_pos.y);
            }
        }
    }


void Item::RenderItem(sf::RenderWindow& window)
{
        window.draw(m_ItemJuice);
}
