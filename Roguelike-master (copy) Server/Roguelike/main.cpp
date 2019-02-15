#include <iostream>
#include <Game.h>
#include <SFML/Network.hpp>

using namespace std;

int main()
{
    //Game game;
    //game.run();

    sf::UdpSocket FirstSocket;

    if (FirstSocket.bind(54000) != sf::Socket::Done)
    {
        cerr << "FirstSocket Bind Isn't working" << std::endl;
    }

    char data[100];
    data[0] = 'A';

    sf::IpAddress recipent = "152.105.67.116";
    unsigned short port = 54000;

    if (FirstSocket.send(data, 1, recipent, port) != sf::Socket::Done)
    {
        cerr << "FirstSocket Send 2 Isn't working" << std::endl;
    }

    std::size_t recieved;
    sf::IpAddress sender;

    if (FirstSocket.receive(data, 100, recieved, sender, port) != sf::Socket::Done)
    {
        cerr << "FirstSocket Recieve Isn't Working" << std::endl;
    }

    std::cout << "Recieved " << recieved << " bytes: '" << data << "' from " << sender << " From port no. " << port << std::endl;

    bool test = true

    while (test == true)
    {

    }

    return 0;
}

// "id:pos:100:320"
