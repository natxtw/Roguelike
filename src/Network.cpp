#include "Network.h"
#include <cstring>
#include <thread>
#include <list>
#include "Queue.h"

using namespace std;

Network::Network()
{
    //ctor
}

Network::~Network()
{
    //dtor
}


// For the server
void Network::StartUp()
{
    std::cout << "Would you like to run the Peer2Peer or Server?" << std::endl << "Press 1 for Server" <<std::endl << "Press 2 for Peer2Peer" << std::endl;
    std::cin >> TcpChoice;

    if (TcpChoice == 1)
    {
        //run server Function
        std::cout << "Running Server" << std::endl;

        CreateListener();
        //  sf::TcpSocket socket = AcceptListener();
    }

    else
    {
        //run Peer2Peer Function
        std::cout << "Running Peer2Peer Client" << std::endl;

//        Connect();
    }
}


void Network::CreateListener()
{
    sf::Socket::Status status = Listener.listen(Port); //listens for the port
    if (status != sf::Socket::Done) //gives error if the socket is not done
    {
        std::cerr << "Listen: " << status << std::endl;
        return;
    }

}

void Network::AcceptListener(Queue<std::string> &queue, std::list<sf::TcpSocket*> &sockets, std::mutex &mtx)
{
    sf::Socket::Status status;
    while(true)
    {
        sf::TcpSocket *Socket = new sf::TcpSocket;
        status = Listener.accept (*Socket);
        {
            std::unique_lock<std::mutex> l(mtx);
            sockets.push_back(Socket);
        }
        if (status != sf::Socket::Done) //gives error if the socket is not done
        {
            std::cerr << "Listen: " << status << std::endl;
            return;
        }
        Receiver *r = new Receiver(Socket, true, queue); //creating an object from the reciever class
        std::thread([r] {r->RecieveLoop();}).detach(); //lambda creating a thread of my reciever object and calling the reciever loop from the class
    }
}

void Network::SendMessage()
{
        Queue<std::string> q;
        std::mutex mutex;
        std::list<sf::TcpSocket*> sockets;
        std::thread(&Network::AcceptListener, this, std::ref(q), std::ref(sockets), std::ref(mutex)).detach();

        while(1)
        {
            std::string st = q.pop(); //adds the string to the queue
            std::cout << "Player: " << st << std::endl;
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


std::string Network::RecieveMessage()
{
    if(Socket.receive(BufferOut, 256, recieved) != sf::Socket::Done)
    {
        std::cout << "The client has recieved a message" << std::endl;
    }
    return (std::string(BufferOut));
}


