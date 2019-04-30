#include "AI.h"

AI::AI()
{
    m_EnemyShape.setFillColor(sf::Color::Red);
    m_EnemyShape.setPosition(-100, -100);
}

AI::~AI()
{
    //dtor
}

void AI::Render(sf::RenderWindow& window)
{
    window.draw(m_EnemyShape);
}

void AI::UpdateAI(sf::Vector2f PosCoords)
{
    AIPos = PosCoords;
    ObjectAI = m_EnemyShape.getPosition();
    EnemyFollowCalculation = atan2(AIPos.x - ObjectAI.y, AIPos.y - ObjectAI.x);
    m_EnemyShape.move(cos(EnemyFollowCalculation) * 5.0f,0);
    m_EnemyShape.move(0, sin(EnemyFollowCalculation) * 5.0f);
}

void AI::SpawnAI()
{
    if (AIAlive == false)
    {
        if((rand()%90) == 0)
        {
            AIAlive = true;
            AIx = rand() % 1280 - 100;
            AIy= rand() % 1040 - 100;
            if(AIx <= 100)
            {
                AIx += 100;
            }

            AIPos.x = AIx;
            AIPos.y = AIy;

            m_EnemyShape.setPosition(AIPos.x, AIPos.y);
            //AIPos = m_EnemyShape.getPosition(); //gets the positonal coords of the AI
        }
    }

}

void AI::UpdateAI1()
{
 int moveai = rand()%100;
    if(moveai == 0 && lastDirection != 1)
    {
        m_EnemyShape.move(0.0f, -5.0f);//up
        lastDirection = 0;
    }
    if(moveai == 1 && lastDirection != 0)
    {
        m_EnemyShape.move(0.0f, 5.0f);//down
        lastDirection = 1;
    }
    if(moveai == 2 && lastDirection != 3)
    {
        m_EnemyShape.move(-5.0f, 0.0f);//left
        lastDirection = 2;
    }
    if(moveai == 3 && lastDirection != 2)
    {
        m_EnemyShape.move(5.0f, 0.0f);//right
        lastDirection = 3;
    }
}

void AI::UpdateAI2()
{

    if(AIPos.x > 1280)
    {
    canMoveS == false;
    } else canMoveS == true;

    if(AIPos.x < 0)
    {
    canMoveN == false;
    } else canMoveN == true;

    if(AIPos.y > 1024)
    {
    canMoveE == false;
    } else canMoveE == true;

    if(AIPos.y < 0)
    {
    canMoveW == false;
    } else canMoveW == true;

    if(timesMoved == 10)
    {
    moveai = rand()%4;
    timesMoved = 0;
    }

    if(moveai == 0 && canMoveN == true)
    {
        m_EnemyShape.move(0.0f, -5.0f);//up
    }
    if(moveai == 1 && canMoveS == true)
    {
        m_EnemyShape.move(0.0f, 5.0f);//down
    }
    if(moveai == 2 && canMoveE == true)
    {
        m_EnemyShape.move(-5.0f, 0.0f);//left
    }
    if(moveai == 3 && canMoveW == true)
    {
        m_EnemyShape.move(5.0f, 0.0f);//right
    }
    timesMoved += 1;
    AIPos = m_EnemyShape.getPosition(); //gets the positonal coords of the AI
}

void AI::HasDied()
{
    AIAlive == false;
    std:: cout << "i have died successfully lol anal" << std::endl;
}




