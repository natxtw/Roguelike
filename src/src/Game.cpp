#include "Game.h"


Game::Game(): window(sf::VideoMode(ScreenWidth, ScreenHeight), "Nathan Taylor (T7091066) C++ Roguelike Project")
{
    for (int i = 0; i < amountOfJuice; i++)
    {
        Items.push_back(Item());
    }

    for (int j = 0; j < amountOfEnemies; j++)
    {
        Enemies.push_back(AI());
    }
}

Game::~Game()
{
    //dtor
}

std::string Receiver::Pack()
{
    std::ostringstream Oss;
    unsigned int PlayerId = 111;
    std::string pID = "Player ID: ";
    Oss << pID << PlayerId << std::endl;
    std::string PackedString = Oss.str();
    return PackedString;
}

void Receiver::Unpack(std::string& PackedString)
{
    std::istringstream Iss;
    Iss.str(PackedString);
    std::string pID = "Player ID: ";
    unsigned int PlayerId;
    Iss >> pID >> PlayerId;
    std::cout << pID << PlayerId << std::endl;
}


void Game::run()
{
    Queue<std::string> q;
    sf::TcpSocket *s = new sf::TcpSocket;
    s->connect("127.0.0.1", 4301);
    Receiver receiver(s, false, q);
    std::thread(&Receiver::RecieveLoop, &receiver).detach();

    Player player1;
    AI EnemyAI;

    while (window.isOpen())
    {
        std::string s;// = Pack();
        q.pop(s);
        std::cout << s << std::endl;
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        player1.Update();
        player1.Movement();
        player1.Shoot(window);

        EnemyAI.Render(window);


        for (int i = 0; i < amountOfJuice; i++)
        {
            if(Items[i].Alive == false)
            {
                Items[i].isActive();
            }

            if(Items[i].Alive == true)
            {
                Items[i].RenderItem(window);
            }

            itemCollision = (player1.m_PlayerShape.getGlobalBounds().intersects(Items[i].m_ItemJuice.getGlobalBounds()));

            if(itemCollision == true)
            {
                Items[i].Alive = false;
                Score ++;
            }
        }

        for (int k = 0; k < amountOfEnemies; k++)
        {


            if(Enemies[k].AIAlive == false)
            {
                Enemies[k].SpawnAI();
            }

            if(Enemies[k].AIAlive == true)
            {
                Enemies[k].Render(window);
            }

            EnemyCollision = (player1.m_PlayerShape.getGlobalBounds().intersects(Enemies[k].m_EnemyShape.getGlobalBounds()));


            if(EnemyCollision == true)
            {
               Enemies[k].AIAlive = false;
               Score --;
            }
            Enemies[k].UpdateAI1();

        }


        //std::cout<< Score << std::endl;
        //Unpack(s);
        // s->send();

        player1.Render(window);
        window.display();
        window.clear();
    }
}
