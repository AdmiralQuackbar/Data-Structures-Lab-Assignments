#ifndef QUEUE_H
#define QUEUE_H

#include "LinkedList.h"

template <class myType>
class Queue : public LinkedList<myType>
{
    public:
	Queue();
	~Queue();
	void enqueue(myType value);
	myType dequeue(); 
	myType& front();
};

#endif
