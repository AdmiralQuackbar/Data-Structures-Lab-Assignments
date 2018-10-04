#include "Queue.cpp"
#include <iostream>

using namespace std;

int main()
{
    //create Queue object of type char
    Queue<char> firstQueue;
    
    //table labels
    cout << "Function Call\tOutput\t\tFront\tQueue\tRear\n";

    //table row function calls/print outs

    /*  cout << "dequeue()\t";
    try {
        cout << firstQueue.dequeue();
    } catch(int a) {
        cout << "exception";
    } 

    cout << "\t\t"; firstQueue.print(); cout << endl; */
    
    cout << "isEmpty()\t" << (firstQueue.isEmpty() ? "true" : "false") << "\t\t"; firstQueue.print(); cout << endl;
    
    cout << "enqueue(D)\t\t"; firstQueue.enqueue('D'); cout << "\t"; firstQueue.print(); cout << endl;
    
    cout << "enqueue(A)\t\t"; firstQueue.enqueue('A'); cout << "\t"; firstQueue.print(); cout << endl;
    
    cout << "dequeue()\t";
    try {
        cout << firstQueue.dequeue();
    } catch(int a) {
        cout << "exception";
    }

    cout << "\t\t"; firstQueue.print(); cout << endl;
   
    cout << "size()\t\t" << firstQueue.size() << "\t\t"; firstQueue.print(); cout << endl;
   
    cout << "enqueue(D)\t\t"; firstQueue.enqueue('D'); cout << "\t"; firstQueue.print(); cout << endl;
    
    cout << "isEmpty()\t" << (firstQueue.isEmpty() ? "true" : "false") << "\t\t"; firstQueue.print(); cout << endl;
   
    cout << "front()\t\t";
    try {
        cout << firstQueue.front();
    } catch(int a) {
        cout << "exception";
    }
    cout << "\t\t"; firstQueue.print(); cout << endl;
   
    cout << "enqueue(T)\t\t"; firstQueue.enqueue('T'); cout << "\t"; firstQueue.print(); cout << endl;
    
    cout << "front()\t\t";
    try {
        cout << firstQueue.front();
    } catch(int a) {
        cout << "exception";
    }
    cout << "\t\t"; firstQueue.print(); cout << endl;

    return 0;
}
