#include <Game.h>
#include <Network.h>
#include <thread>
#include <mutex>
#include <Queue.h>
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
        // 0. Create queue
        Receiver receiver;
        // receiver needs to connect
        // receiver needs to send
        // 1. Run receiver thread
        std::thread(&Receiver::RecieveLoop(), &receiver).detach();
        //Game game(q);
        //game.run();
    }
    else
    {
        Network network;
        network.CreateListener();

        Queue<std::string> q;
        std::mutex mutex;
        std::list<sf::TcpSocket*> sockets;
        std::thread(&Network::AcceptListener, &network, std::ref(q), std::ref(sockets), std::ref(mutex)).detach();

        while(1)
        {
            std::string st = q.pop(); // Blocking!
            std::cout << "Main read: '" << st << "'\n";
            {
                std::unique_lock<std::mutex> l(mutex);
                for (auto socket : sockets)
                {
                    sf::Socket::Status status = socket->send(st.c_str(), st.size());
                    if (status != sf::Socket::Done)
                    {
                        std::cout << "Sending failed: " << status << std::endl;
                    }
                }
            }
        }
    }

    return 0;
}




