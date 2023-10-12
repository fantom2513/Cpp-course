#include "FineGrainedQueue.h"
#include <iostream>

FineGrainedQueue::FineGrainedQueue()
{
    head = new Node();
    head->next = nullptr;
    head->value = 0;
    head->node_mutex = new std::mutex();

    queue_mutex = new std::mutex();
}

void FineGrainedQueue::remove(int value)
{
    Node* prev, * cur;
    queue_mutex->lock();

    

    prev = this->head;
    cur = this->head->next;

    prev->node_mutex->lock();
    
    queue_mutex->unlock();

    if (cur) 
        cur->node_mutex->lock();
    while (cur)
    {
        if (cur->value == value)
        {
            prev->next = cur->next;
            prev->node_mutex->unlock();
            cur->node_mutex->unlock();
            delete cur;
            return;
        }
        Node* old_prev = prev;
        prev = cur;
        cur = cur->next;
        old_prev->node_mutex->unlock();
        if (cur) 
            cur->node_mutex->lock();
    }
    prev->node_mutex->unlock();
}

void FineGrainedQueue::insert(int value)
{
    Node* newN = new Node();
    newN->value = value;
    newN->next = nullptr;
    newN->node_mutex = new std::mutex();

    Node* cur = head;
    while (cur->next != nullptr) {
        cur = cur->next;
    }
    cur->next = newN;
}

void FineGrainedQueue::insertIntoMiddle(int value, int pos)
{
    int curPos = 1;
    Node * cur, * newN = new Node();
    newN->value = value;
    newN->node_mutex = new std::mutex();
    queue_mutex->lock();
    cur = this->head;
    queue_mutex->unlock();

    if (cur) 
        cur->node_mutex->lock();
    while (cur)
    {
        if (curPos == pos)
        {
            newN->node_mutex->lock();
            newN->next = cur->next;
            cur->next = newN;            
            newN->node_mutex->unlock();
            cur->node_mutex->unlock();
            return;
        }
        Node* old_cur = cur;
        cur = cur->next;
        if (cur) 
            cur->node_mutex->lock();
        else { 
            newN->node_mutex->lock();
            newN->next = old_cur->next;
            old_cur->next = newN;
            newN->node_mutex->unlock();
            old_cur->node_mutex->unlock();
            return;
        }
        curPos++;
        old_cur->node_mutex->unlock();
    }
    newN->node_mutex->unlock();
}

void FineGrainedQueue::print()
{
    Node* cur = head;
    while (cur->next != nullptr) {
        std::cout << cur->value << " ";
        cur = cur->next;
    }
    std::cout << cur->value << std::endl;
}
