#include "Queue.h"
#include "LinkedList.h"
#include <iostream>

using namespace std;

int main()
{
    //create stack object of type int
    Queue<int> firstQueue;

    //Table Labels
    cout << "Function call\tOutput\tQueue Contents" << endl;

    //First 10 enqueue lines
    cout << "enqueue(5)\t\t"; firstQueue.enqueue(5); firstQueue.print(); cout << endl;
    cout << "enqueue(7)\t\t"; firstQueue.enqueue(7); firstQueue.print(); cout << endl;
    cout << "enqueue(-7)\t\t"; firstQueue.enqueue(-7); firstQueue.print(); cout << endl;
    cout << "enqueue(0)\t\t"; firstQueue.enqueue(0); firstQueue.print(); cout << endl;
    cout << "enqueue(10)\t\t"; firstQueue.enqueue(10); firstQueue.print(); cout << endl;
    cout << "enqueue(-5)\t\t"; firstQueue.enqueue(-5); firstQueue.print(); cout << endl;
    cout << "enqueue(-10)\t\t"; firstQueue.enqueue(-10); firstQueue.print(); cout << endl;
    cout << "enqueue(37)\t\t"; firstQueue.enqueue(37); firstQueue.print(); cout << endl;
    cout << "enqueue(27)\t\t"; firstQueue.enqueue(27); firstQueue.print(); cout << endl;
    cout << "enqueue(98)\t\t"; firstQueue.enqueue(98); firstQueue.print(); cout << endl;
    cout << "enqueue(101)\t\t"; firstQueue.enqueue(101); firstQueue.print(); cout << endl;

    //dequeue line
    cout << "dequeue()\t";
    try {
        cout << firstQueue.dequeue() << "\t";
    } catch(int a) {
        cout << "exception\t";
    }  
    firstQueue.print(); cout << endl;

    //front line
    cout << "front()\t\t";
    try {
        cout << firstQueue.front() << "\t";
    } catch (int a) {
        cout << "exception\t";
    }
    firstQueue.print(); cout << endl;

    //size line
    cout << "size()\t\t" << firstQueue.size() << "\t"; firstQueue.print(); cout << endl;

    //isEmpty line
    cout << "isEmpty()\t" << (firstQueue.isEmpty() ? "true" : "false") << "\t"; firstQueue.print(); cout << endl;

    return 0;
}
