#ifndef ITEM_H
#define ITEM_H

#include <SFML/Graphics.hpp>


class Item
{
    public:
        Item();
        virtual ~Item();

        void RenderItem(sf::RenderWindow& window);
        void isActive();


        int xAligned{0};
        int yAligned{0};
        sf::Vector2f m_pos{0,0};
        bool Alive{false};
        sf::CircleShape m_ItemJuice{40.0f};

    protected:

    private:

        std::vector<int> ItemStorage;
};

#endif // ITEM_H
