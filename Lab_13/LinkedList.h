#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

using namespace std;

// Representation of an element in the linked list
template<class T>
struct Node
{
    T val; // Value of the node
    Node *next; // Pointer to the next node
};

template<class T>
class LinkedList
{
    // Public Functions/Variables
    public:
        /* IMPLEMENT THESE FUNCTIONS FOR EXERCISE1 */
        LinkedList(); // Constructor
        ~LinkedList(); // Destructor
        void insertAtBack(T valueToInsert);
        bool removeFromBack();
        void print();
        bool isEmpty();
        int size();
        void clear();

        /* IMPLEMENT THESE FUNCTIONS FOR EXERCISE2 */
        void insertAtFront(T valueToInsert);
        bool removeFromFront();

        Node<T> *first; // Pointer pointing to the begining of the list
        Node<T> *last; // Pointer pointing to the end of the list
};

template<class T>
LinkedList<T>::LinkedList()
{
    last = NULL;
    first = last;
}

template<class T>
LinkedList<T>::~LinkedList()
{
    while (!isEmpty()) 
    {
      Node<T>* temp = new Node<T>;
        temp = first;
        first = first->next;
        delete temp;
    }
}

template<class T>
void LinkedList<T>::insertAtBack(T valueToInsert)
{
    if(isEmpty()) {
      Node<T>* back = new Node<T>;
        back->val = valueToInsert;
        first = back;
        last = back;
    }
    else {
      Node<T>* back = new Node<T>;
        back->val = valueToInsert;
        last->next = back;
        last = back;
    }
}

template<class T>
bool LinkedList<T>::removeFromBack()
{
    if(first != NULL) 
    {   
      Node<T>* old = new Node<T>;
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

template<class T>
void LinkedList<T>::print()
{
    if(!isEmpty())
    {
        Node<T>* temp = new Node<T>;
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

template<class T>
bool LinkedList<T>::isEmpty()
{
    return (first == NULL);
}

template<class T>
int LinkedList<T>::size()
{
    int count = 0;
    Node<T>* temp = new Node<T>;
    temp = first;
    while (temp != NULL) 
    { 
      ++count; 
      temp = temp->next; 
    }
    delete temp;
    return count;
}

template<class T>
void LinkedList<T>::clear()
{
    while (!isEmpty()) 
    {
        Node<T>* temp = new Node<T>;
        temp = first;
        first = first->next;
        delete temp;
    }
}

template<class T>
void LinkedList<T>::insertAtFront(T valueToInsert)
{
    Node<T>* front = new Node<T>;
    front->val = valueToInsert;
    front->next = first;
    first = front;
}

template<class T>
bool LinkedList<T>::removeFromFront()
{
    if(first != NULL) {
        Node<T>* old = new Node<T>;
        old = first;
        first = first->next;
        delete old;
        return true;
    }
    return false;
}

// Implement your functions here:



#endif

