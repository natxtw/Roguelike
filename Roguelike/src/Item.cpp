#include "Item.h"

Item::Item()
{
    //ctor
    m_ItemJuice.setFillColor(sf::Color(100, 250, 50));
}

Item::~Item()
{
    //dtor
}

void Item::RenderItem(sf::RenderWindow& window)
{
    window.draw(m_ItemJuice);
}
