#ifndef RECEIVER_H
#define RECEIVER_H

#include <SFML/Network.hpp>
#include <iostream>
#include <sstream>
#include <cstring>

#include "Queue.h"


class Receiver
{
    public:

    Receiver(sf::TcpSocket* S, bool server, Queue<std::string>& queue);
    void RecieveLoop();
    // send
    void ClientConnect();

    std::string Pack();
    void Unpack(std::string& UnpackString);

    private:
    unsigned short Port = 4301;
    sf::TcpSocket* Socket;
    bool IsServer = false;
    Queue<std::string> &queue;
    sf::IpAddress RemoteAddress;
    sf::Time Timeout = sf::seconds(60.0f);
    sf::TcpListener ClientListener;

};

#endif // RECEIVER_H
