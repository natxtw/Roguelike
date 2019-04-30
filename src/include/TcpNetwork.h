#ifndef TCPNETWORK_H
#define TCPNETWORK_H

#include <SFML/Network.hpp>
#include <iostream>

//using namespace std;

class TcpNetwork
{
    public:
        TcpNetwork();
        virtual ~TcpNetwork();

        int TcpChoice;
        unsigned short Port;
        char BufferIn [256];
        std::size_t sent;
        char BufferOut[256];
        std::size_t recieved;

        sf::TcpListener Listener;
        sf::TcpSocket Client;
        sf::IpAddress RemoteAddress;
        sf::TcpSocket Socket;

        sf::Time Timeout = sf::seconds(60.0f);

        void TcpStartUp();
        void CreateListener();
        void AcceptListener();
        void Connect();
        void SendMessage(std::string to_send);
        std::string RecieveMessage();

    protected:

    private:
};

#endif // TCPNETWORK_H
