#ifndef TCPNETWORK_H
#define TCPNETWORK_H

#include <SFML/Network.hpp>
#include <iostream>
#include <Queue.h>
#include <Receiver.h>
#include <list>
#include <cstring>
#include <thread>

using namespace std;

class Network
{
    public:
        Network();
        virtual ~Network();

        int TcpChoice;
        unsigned short Port = 4301;
        char BufferIn [256];
        std::size_t sent;
        char BufferOut[256];
        std::size_t recieved;
        std::mutex mtx;

        sf::TcpListener Listener;
        sf::TcpSocket Client;
        sf::TcpSocket Socket;

        void StartUp();
        void CreateListener();
        void AcceptListener(Queue<std::string> &queue, std::list<sf::TcpSocket*> &Socket, std::mutex &mtx);
        void Connect();
        void SendMessage();
        Queue<std::string> q;
        std::string RecieveMessage();

    protected:

    private:

};

#endif // TCPNETWORK_H
