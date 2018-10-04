#include "LinkedList.h"
#include <iostream>

using namespace std;

template<class myType>
LinkedList<myType>::LinkedList()
{
    last = NULL;
    first = last;
}

template<class myType>
LinkedList<myType>::~LinkedList()
{
    while (!isEmpty()) 
    {
      Node<myType>* temp = new Node<myType>;
        temp = first;
        first = first->next;
        delete temp;
    }
}

template<class myType>
void LinkedList<myType>::insertAtBack(myType valueToInsert)
{
    if(isEmpty()) {
      Node<myType>* back = new Node<myType>;
        back->val = valueToInsert;
        first = back;
        last = back;
    }
    else {
      Node<myType>* back = new Node<myType>;
        back->val = valueToInsert;
        last->next = back;
        last = back;
    }
}

template<class myType>
bool LinkedList<myType>::removeFromBack()
{
    if(first != NULL) 
    {   
      Node<myType>* old = new Node<myType>;
        old = first;
        if(first == last) {
            first = NULL;
            delete old;
            return true;
        }
        while(old->next != last) {
            old = old->next;
        }
        old->next = NULL;
        last = old;
        return true;
    }   
    return false;
}

template<class myType>
void LinkedList<myType>::print()
{
    if(!isEmpty())
    {
        Node<myType>* temp = new Node<myType>;
        temp = first;
        cout << temp->val;
        temp = temp->next;
        while(temp != NULL) 
        {
            cout << ", " << temp->val;
            temp = temp->next;
        }
    }
}

template<class myType>
bool LinkedList<myType>::isEmpty()
{
    return (first == NULL);
}

template<class myType>
int LinkedList<myType>::size()
{
    int count = 0;
    Node<myType>* temp = new Node<myType>;
    temp = first;
    while (temp != NULL) 
    { 
      ++count; 
      temp = temp->next; 
    }
    delete temp;
    return count;
}

template<class myType>
void LinkedList<myType>::clear()
{
    while (!isEmpty()) 
    {
        Node<myType>* temp = new Node<myType>;
        temp = first;
        first = first->next;
        delete temp;
    }
}

template<class myType>
void LinkedList<myType>::insertAtFront(myType valueToInsert)
{
    Node<myType>* front = new Node<myType>;
    front->val = valueToInsert;
    front->next = first;
    first = front;
}

template<class myType>
bool LinkedList<myType>::removeFromFront()
{
    if(first != NULL) {
        Node<myType>* old = new Node<myType>;
        old = first;
        first = first->next;
        delete old;
        return true;
    }
    return false;
}

template class LinkedList<int>;
template class LinkedList<char>;