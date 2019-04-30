#include "Receiver.h"

Receiver::Receiver(sf::TcpSocket* S, bool server, Queue<std::string>& queue): Socket(S), IsServer(server), queue(queue){}

void Receiver::RecieveLoop()
{
    char buffer[256];

    while(1)
    {
        std::memset(buffer, 0, 256); // Will fill the block of memory with any missing data
        std::size_t received; //checks the size of the message recieved
        sf::Socket::Status status = Socket->receive(buffer, 256, received);

        if (status != sf::Socket::Done)
        {
            std::cerr << "Receive: " << status << std::endl; //displays the error in the console
            return;
        }
            queue.push(std::string(buffer)); //prints the message
    }
}

void Receiver::ClientConnect()
{
    sf::Socket::Status status = Socket->connect(RemoteAddress, Port); //listens for the ip and port
    if (status != sf::Socket::Done)
    {
        std::cout << "The client has not connected" << std::endl; //Client can't connect error message
    }

}


