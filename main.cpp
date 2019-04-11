#include <Game.h>
#include <Network.h>
#include <thread>
#include <Queue.h>
#include <Receiver.h>
#include <SFML/Network.hpp>


#include <iostream>

using namespace std;

int main()
{

    char isClient;
    std::cout << "Do you want to run as a server(1) or client(2)?" << std::endl;
    std::cin >> isClient;
    isClient -= '1';

    if(isClient)
    {
       /* Queue<std::string> q;
        sf::TcpSocket *s = new sf::TcpSocket;
        s->connect("127.0.0.1", 4301);
        Receiver receiver(s, false, q);
        std::thread(&Receiver::RecieveLoop, &receiver).detach();

        while (1) //goes in the game class
        {
            std::string s = q.pop();
            std::cout << s << std::endl;
        }   */

        Game game; //(q);
        game.run();

    }
    else
    {
        Network network;
        network.CreateListener();
        network.SendMessage();
    }

    return 0;
}

// link to sprites used - https://opengameart.org/content/tower-defense-grass-background
