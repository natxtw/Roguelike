#ifndef QUEUE_H
#define QUEUE_H

#include <queue>
#include <SFML/Network.hpp>
#include <mutex>
#include <iostream>
#include <condition_variable>

template <typename T>

class Queue
{
    public:
        T pop()
        {
            std::unique_lock<std::mutex> mtxlock(Mutex_); //locks the mutex
            CondVar_.wait(mtxlock, [this]{return !Queue_.empty();}); //returns to waiting if there's no message
            auto val = Queue_.front(); //gets the message from the queue
            Queue_.pop(); //removes the front of the queue
            return val; //returns the val
        }

        void pop(T& test)
        {
            std::unique_lock<std::mutex> mtxlock(Mutex_); //locks the mutex
            if (Queue_.empty()) //returns if there's nothing in the queue
            {
                return;
            }
            test = Queue_.front(); //gets the front of the queue
            Queue_.pop(); // removes the front element from the queue
        }

        void push(const T& test)
        {
            std::unique_lock<std::mutex> mtxlock (Mutex_); //locks the mutex
            Queue_.push(test); //pushes the test to the end of the queue
            CondVar_.notify_one(); //unblocks the thread that's waiting for the condition
        }

        Queue()=default;
        Queue(const Queue&) = delete; //disables copying
        Queue& operator=(const Queue&) = delete; //disables assignment

    protected:

    private:
    std::queue<T> Queue_;
    std::mutex Mutex_;
    std::condition_variable CondVar_;
};

#endif // QUEUE_H
