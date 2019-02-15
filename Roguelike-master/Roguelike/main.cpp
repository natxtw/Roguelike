#include <iostream>
#include <Game.h>
#include <SFML/Network.hpp>
#include <cstring>

using namespace std;

int main()
{
    //Game game;
    //game.run();

    sf::UdpSocket FirstSocket;

    unsigned short port = 54000;

    if (FirstSocket.bind(port) != sf::Socket::Done)
    {
        cerr << "FirstSocket Bind Isn't working" << std::endl;
    }

    char data[100];
    std::memset(data, 0, 100);

    sf::IpAddress remote_host;
    unsigned short remote_port;

    std::size_t recieved;

    bool SendDataBool = true;

    while (SendDataBool == true)
    {
        if (FirstSocket.receive(data, 100, recieved, remote_host, remote_port) != sf::Socket::Done)
        {
            cerr << "FirstSocket Recieve Isn't Working" << std::endl;
        }

        std::cout << "Recieved " << recieved << " bytes: '" << data << "' from " << remote_host << " From port no. " << remote_port << std::endl;


        if (FirstSocket.send(data, 100, remote_host, remote_port) != sf::Socket::Done)
        {
            cerr << "FirstSocket Send 2 Isn't working" << std::endl;
        }
    }


    return 0;
}

// "id:pos:100:320"
