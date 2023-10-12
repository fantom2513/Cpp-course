#include <iostream>
#include <thread>
#include "FineGrainedQueue.h"

int main()
{
    FineGrainedQueue* que = new FineGrainedQueue();
    que->insert(1);
    que->insert(2);
    que->insert(3);
    que->insert(4);

    que->print();
    
    std::thread t1(&FineGrainedQueue::insertIntoMiddle, que, 20, 3);
    std::thread t2(&FineGrainedQueue::insertIntoMiddle, que, 30, 7);

    t1.join();
    t2.join();

    que->print();
}
