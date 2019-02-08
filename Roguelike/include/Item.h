#ifndef ITEM_H
#define ITEM_H

#include <SFML/Graphics.hpp>


class Item
{
    public:
        Item();
        virtual ~Item();

        void RenderItem(sf::RenderWindow& window);

    protected:

    private:
        sf::CircleShape m_ItemJuice{40.f};
};

#endif // ITEM_H
