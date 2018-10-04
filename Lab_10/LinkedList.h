#ifndef LINKEDLIST_H 
#define LINKEDLIST_H

using namespace std; 

// Representation of an element in the linked list
template <class myType>
struct Node 
{
    myType val;// Value of the node
    Node<myType> *next; // Pointer to the next node
};

template <class myType>
class LinkedList 
{
    // Public Functions/Variables
    public:
        /* IMPLEMENT THESE FUNCTIONS FOR EXERCISE1 */
        LinkedList(); // Constructor
        ~LinkedList(); // Destructor
        void insertAtBack(myType valueToInsert);
        bool removeFromBack();
        void print();
        bool isEmpty();
        int size();
        void clear();

        /* IMPLEMENT THSES FUNCTIONS FOR EXERCISE2 */
        void insertAtFront(myType valueToInsert);
        bool removeFromFront();

    // Private Functions/Variables
    
        Node<myType> *first; // Pointer pointing to the begining of the list
        Node<myType> *last; // Pointer pointing to the end of the list
};

#endif
