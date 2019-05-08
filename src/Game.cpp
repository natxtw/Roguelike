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

        std::thread t(&Player::Update, &player1);


        player1.Movement();
        player1.Shoot(window);
        EnemyAI.Render(window);

        sf::Font font;
        if(!font.loadFromFile("Quantum.otf"))
        {
            std::cout << "Error Loading Font" << std::endl;
        }

        sf::Text ScoreText;
        ScoreText.setFont(font);
        ScoreText.setString("Score:");
        ScoreText.setCharacterSize(20);
        ScoreText.setPosition(0,0);

        sf::Text ScoreNumber;
        ScoreNumber.setFont(font);
        ScoreNumber.setString(std::to_string(Score));
        ScoreNumber.setCharacterSize(20);
        ScoreNumber.setPosition(80,0);

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

            if((player1.m_PlayerShape.getGlobalBounds().intersects(Items[i].m_ItemJuice.getGlobalBounds())))
            {
                Items[i].Alive = false;
                player1.FireTheAmmo += 1;
                Score ++;
                std::cout << "i work" << std::endl;
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

            if((player1.m_PlayerShape.getGlobalBounds().intersects(Enemies[k].m_EnemyShape.getGlobalBounds())))
            {
               Enemies[k].AIAlive = false;
               Score --;
            }

            Enemies[k].UpdateAI2();

            for (int l = 0; l < player1.CurrentAmmo; l++)
            {
                if (player1.BulletCount[l].BulletSprite.getGlobalBounds().intersects(Enemies[k].m_EnemyShape.getGlobalBounds()))
                {
                    Enemies[k].AIAlive = false;
                    Score += 32;
                }

            for (int z = 0; z < player1.WindPower; z++)
            {
                if (player1.WindCount[z].BulletSprite.getGlobalBounds().intersects(Enemies[k].m_EnemyShape.getGlobalBounds()))
                {
                    Enemies[k].AIAlive = false;
                    Score -=3;
                }
            }
        }

        }




        std::cout<< Score << std::endl;
        //Unpack(s);
        // s->send();

        t.join();
        player1.Render(window);
        window.draw(ScoreText);
        window.draw(ScoreNumber);
        window.display();
        window.clear();
    }
}


