#include "LinkedList.h"
#include <iostream>

using namespace std;

LinkedList::LinkedList()
{
    last = NULL;
    first = last;
}

LinkedList::~LinkedList()
{
    while (!isEmpty()) 
    {
        Node* temp = new Node;
        temp = first;
        first = first->next;
        delete temp;
    }
}

void LinkedList::insertAtBack(int valueToInsert)
{
    if(isEmpty()) {
        Node* back = new Node;
        back->val = valueToInsert;
        first = back;
        last = back;
    }
    else {
        Node* back = new Node;
        back->val = valueToInsert;
        last->next = back;
        last = back;
    }
}

bool LinkedList::removeFromBack()
{
    if(first != NULL) 
    {   
        Node* old = new Node;
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

void LinkedList::print()
{
    if(!isEmpty())
    {
        Node* temp = new Node;
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

bool LinkedList::isEmpty()
{
    return (first == NULL);
}

int LinkedList::size()
{
    int count = 0;
    Node* temp = new Node;
    temp = first;
    while (temp != NULL) 
    { 
      ++count; 
      temp = temp->next; 
    }
    delete temp;
    return count;
}

void LinkedList::clear()
{
    while (!isEmpty()) 
    {
        Node* temp = new Node;
        temp = first;
        first = first->next;
        delete temp;
    }
}

void LinkedList::insertAtFront(int valueToInsert)
{
    Node* front = new Node;
    front->val = valueToInsert;
    front->next = first;
    first = front;
}

bool LinkedList::removeFromFront()
{
    if(first != NULL) {
        Node* old = new Node;
        old = first;
        first = first->next;
        delete old;
        return true;
    }
    return false;
}
