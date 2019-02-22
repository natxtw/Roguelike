#include <iostream>
#include <Game.h>
#include <TcpNetwork.h>

using namespace std;

int main()
{
    //Game game;
    //game.run();

    TcpNetwork network;
    network.TcpStartUp();

    return 0;
}
