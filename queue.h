#ifndef _QUEUE_H_
#define _QUEUE_H_

#include<list>
using namespace std;

template<typename T> class Queue:public list<T>
{
public:
    void enqueue(T const& e){this->push_back(e);}
    T dequeue(){ T e=this->front();this->pop_front();return e;}
};

#endif // _QUEUE_H_
