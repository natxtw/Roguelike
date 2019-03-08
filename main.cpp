#include <iostream>
#include <Game.h>
#include <TcpNetwork.h>
#include <thread>
#include <vector>
#include <mutex>

#include <iostream>

using namespace std;

struct DataStorage
{
    void ParamFunct(int Param1, int Param2, int Param3)
    {
        std::cout << Param1*Param2*Param3 << std::endl;
    }

    int SoloInt; //Possible to hard code it
    DataStorage() : SoloInt(0){} //declaring via the constructor
    std::mutex mutex;


    void increment()
    {
        std::lock_guard<std::mutex> Guard(mutex);
        SoloInt++;
    }
};



int main()
{
    //Game game;
    //game.run();

    //TcpNetwork network;
    //network.TcpStartUp();

    DataStorage MyStruct;

    std::vector<std::thread> VecThread; //A containor(vector) of threads
    for (int i = 0; i < 10; i++) //An Iterator- for statement that can point to an element inside the containor(vector)
    {
        VecThread.push_back(std::thread([&MyStruct]() //Using a Lambda to declare an unnamed new function
        {
            for (int i = 0; i < 100; i++)
            {
                MyStruct.increment();
            }
        }));
    }

    for (auto& thread_ : VecThread)
    {
        thread_.join(); //Waits for the thread(s) to finish
    }

    std::cout << MyStruct.SoloInt << std::endl;

 //   std::thread{&DataStorage::ParamFunct, &MyStruct, 15, 5, 42}.join(); // not very relative to the other code in the main




    return 0;
}




