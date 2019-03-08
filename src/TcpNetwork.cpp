#include "TcpNetwork.h"
#include <cstring>

TcpNetwork::TcpNetwork()
{
    //ctor
}

TcpNetwork::~TcpNetwork()
{
    //dtor
}


// For the server
void TcpNetwork::TcpStartUp()
{
    std::cout << "Would you like to run the Peer2Peer or Server?" << std::endl << "Press 1 for Server" <<std::endl << "Press 2 for Peer2Peer" << std::endl;
    std::cin >> TcpChoice;

    if (TcpChoice == 1)
    {
        //run server Function
        std::cout << "Running Server" << std::endl;

        CreateListener();
        TcpSocket socket = AcceptListener();
    }

    else
    {
        //run Peer2Peer Function
        std::cout << "Running Peer2Peer Client" << std::endl;

//        Connect();
    }
}




void TcpNetwork::CreateListener()
{
    if (Listener.listen(Port) != sf::Socket::Done)
    {
        std::cerr << "Tcp Listener is not working" << std::endl;
    }

}

void TcpNetwork::AcceptListener()
{
    if (Listener.accept(Client) == sf::Socket::Done)
    {
        std::cout << "A new client is trying to connect" << std::endl;
        //add a function "like do something with(client)"
    }
    return Client;
}

void TcpNetwork::Connect()
{
    if (Socket.connect(RemoteAddress,Port, Timeout) != sf::Socket::Done)
    {
        std::cout << "The client has not connected" << std::endl;
    }

}

void TcpNetwork::SendMessage(std::string to_send)
{
    std::memcpy(BufferIn, to_send.c_str(), to_send.size());
    if (Socket.send(BufferIn, to_send.size()) != sf::Socket::Done)
    {
        std::cout << "The client has sent a message" << std::endl;
    }
}

std::string TcpNetwork::RecieveMessage()
{
    if(Socket.receive(BufferOut, 256, recieved) != sf::Socket::Done)
    {
        std::cout << "The client has recieved a message" << std::endl;
    }
    return (std::string(BufferOut));
}

