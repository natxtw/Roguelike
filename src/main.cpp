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
        Game game;
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

