#ifndef TCPNETWORK_H
#define TCPNETWORK_H

#include <SFML/Network.hpp>
#include <iostream>
#include <Queue.h>
#include <Receiver.h>
#include <list>

using namespace std;

class Network
{
    public:
        Network();
        virtual ~Network();

        int TcpChoice;
//        unsigned short Port = 4301; //now in reciever
        char BufferIn [256];
        std::size_t sent;
        char BufferOut[256];
        std::size_t recieved;
        std::mutex mtx;

        sf::TcpListener Listener;
        sf::TcpSocket Client;
//        sf::IpAddress RemoteAddress; //mow in reciever
        sf::TcpSocket Socket;

        void StartUp();
        void CreateListener();
        void AcceptListener(Queue<std::string> &queue, std::list<sf::TcpSocket*> &Socket, std::mutex &mtx);
        void Connect();
        void SendMessage(std::string to_send);
        std::string RecieveMessage();

    protected:

    private:
};

#endif // TCPNETWORK_H
