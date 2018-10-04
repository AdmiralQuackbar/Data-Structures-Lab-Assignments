#include "Queue.h"
#include "LinkedList.cpp"
#include <iostream>

using namespace std;

template<class myType>
Queue<myType>::Queue() :LinkedList<myType>::LinkedList(){}

template<class myType>
Queue<myType>::~Queue() {}

template<class myType>
void Queue<myType>::enqueue(myType value)
{
    LinkedList<myType>::insertAtBack(value);
}

template<class myType>
myType Queue<myType>::dequeue()
{
  if(LinkedList<myType>::first == NULL) {
        throw 37;
    }
    int temp = LinkedList<myType>::first->val;
    if(LinkedList<myType>::removeFromFront()) {
        return temp; 
    }  
}

template<class myType>
myType& Queue<myType>::front()
{
  if(LinkedList<myType>::first == NULL) {
        throw 10;
    }
    return LinkedList<myType>::first->val;
} 

