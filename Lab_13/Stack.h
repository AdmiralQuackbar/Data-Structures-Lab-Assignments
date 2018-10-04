#ifndef STACK_H
#define STACK_H

#include "LinkedList.h"

template <class T>
class Stack : public LinkedList<T>
{
    public:
	Stack();
	~Stack();
	void push(T value);
	T pop();
	T& top();
};

template<class T>
Stack<T>::Stack() :LinkedList<T>::LinkedList(){}

template<class T>
Stack<T>::~Stack() {}

template<class T>
void Stack<T>::push(T value)
{
    LinkedList<T>::insertAtFront(value);
}

template<class T>
T Stack<T>::pop()
{
  if(!(LinkedList<T>::isEmpty())) {
        int temp = LinkedList<T>::first->val;
        LinkedList<T>::removeFromFront();
        return temp;
    }   
}

template<class T>
T& Stack<T>::top()
{
    return LinkedList<T>::first->val;
}

#endif
