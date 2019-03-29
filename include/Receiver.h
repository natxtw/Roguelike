#ifndef RECEIVER_H
#define RECEIVER_H

#include <SFML/Network.hpp>
#include <iostream>
#include <cstring>

#include "Queue.h"


class Receiver
{
    public:
//    Receiver();
//    virtual ~Receiver();

    Receiver(sf::TcpSocket* S, bool server, Queue<std::string>& queue);
    void RecieveLoop();

    private:
    sf::TcpSocket* Socket;
    bool IsServer = false;
    Queue<std::string> &queue;



};

#endif // RECEIVER_H
