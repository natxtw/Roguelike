#ifndef THREADS_H
#define THREADS_H
#include <SFML/System.hpp>
#include <iostream>

class Threads
{
    public:
        Threads();
        virtual ~Threads();

        sf::Thread FirstThread(); //Within the brackets is the entry point


        void TestCout();

    protected:

    private:
};

#endif // THREADS_H
