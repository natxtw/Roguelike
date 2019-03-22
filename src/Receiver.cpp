#include "Receiver.h"

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

        if (IsServer)
        {
            queue.push(std::string(buffer)); //prints the message
        }
    }
}
