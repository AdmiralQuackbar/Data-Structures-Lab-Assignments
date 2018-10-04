#ifndef STACK_H
#define STACK_H

#include "LinkedList.h"

template <class myType>
class Stack : public LinkedList<myType>
{
    public:
	Stack();
	~Stack();
	void push(myType value);
	myType pop();
	myType& top();
};

#endif
