#ifndef AI_H
#define AI_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <Bullets.h>

class AI
{
    public:
        AI();
        virtual ~AI();

        void Render(sf::RenderWindow& window);
        void UpdateAI(sf::Vector2f PosCoords);
        void UpdateAI1();
        void UpdateAI2();

        void HasDied();

        void SpawnAI();

        sf::CircleShape m_EnemyShape{20.f};
        float AIx;
        float AIy;
        sf::Vector2f AIPos{0.0f, 0.0f};
        sf::Vector2f ObjectAI{0.0f, 0.0f};
        std::vector<int> EnemyCount;
        bool AIAlive{false};
        float EnemyFollowCalculation;


    protected:

    private:

    int lastDirection{0};
    int timesMoved{10};
    int moveai{0};
    bool canMoveN{true};
    bool canMoveE{true};
    bool canMoveS{true};
    bool canMoveW{true};
};

#endif // AI_H
