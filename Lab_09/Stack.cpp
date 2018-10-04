#include "Stack.h"

template<class myType>
Stack<myType>::Stack() :LinkedList<myType>::LinkedList(){}

template<class myType>
Stack<myType>::~Stack() {}

template<class myType>
void Stack<myType>::push(myType value)
{
    LinkedList<myType>::insertAtFront(value);
}

template<class myType>
myType Stack<myType>::pop()
{
  if(!(LinkedList<myType>::isEmpty())) {
        int temp = LinkedList<myType>::first->val;
        LinkedList<myType>::removeFromFront();
        return temp;
    }   
}

template<class myType>
myType& Stack<myType>::top()
{
    return LinkedList<myType>::first->val;
}

template class Stack<int>;
template class Stack<char>;