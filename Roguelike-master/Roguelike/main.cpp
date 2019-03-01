#include <iostream>
#include <Game.h>
#include <TcpNetwork.h>
#include <thread>
#include <vector>

using namespace std;

struct DataStorage
{
    void ParamFunct(int Param1, int Param2, int Param3);
};

void randomfunct()
{
        std::cout << " Function thread " << std::this_thread::get_id() << std::endl;
}

int main()
{
    //Game game;
    //game.run();

    //TcpNetwork network;
    //network.TcpStartUp();

/*    std::thread FirstThread(&randomfunct); //Within the brackets is the entry point
      std::cout << " Main thread " << std::endl;
      FirstThread.join(); //Waits to end the thread
*/
    DataStorage MyStruct;

    std::vector<std::thread> VecThread;

    for (int i = 0; i < 10; i++)
    {
        VecThread.push_back(std::thread(randomfunct));
    }

    for (auto& thread_ : VecThread)
    {
        thread_.join();
    }


    return 0;
}
