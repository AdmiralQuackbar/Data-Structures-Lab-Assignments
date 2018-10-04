#include "Stack.h"
#include "LinkedList.h"
#include <iostream>

using namespace std;

int main()
{
    //create stack object of type int
    Stack<int> firstStack;

    //Table Labels
    cout << "Function call\tOutput\tStack Contents" << endl;

    //First 10 push lines
    cout << "push(5)\t\t\t"; firstStack.push(5); firstStack.print(); cout << endl;
    cout << "push(7)\t\t\t"; firstStack.push(7); firstStack.print(); cout << endl;
    cout << "push(-7)\t\t"; firstStack.push(-7); firstStack.print(); cout << endl;
    cout << "push(0)\t\t\t"; firstStack.push(0); firstStack.print(); cout << endl;
    cout << "push(10)\t\t"; firstStack.push(10); firstStack.print(); cout << endl;
    cout << "push(-5)\t\t"; firstStack.push(-5); firstStack.print(); cout << endl;
    cout << "push(-10)\t\t"; firstStack.push(-10); firstStack.print(); cout << endl;
    cout << "push(37)\t\t"; firstStack.push(37); firstStack.print(); cout << endl;
    cout << "push(27)\t\t"; firstStack.push(27); firstStack.print(); cout << endl;
    cout << "push(98)\t\t"; firstStack.push(98); firstStack.print(); cout << endl;
    cout << "push(101)\t\t"; firstStack.push(101); firstStack.print(); cout << endl;

    //pop line
    cout << "pop()\t\t"; cout << firstStack.pop() << "\t"; firstStack.print(); cout << endl;

    //top line
    cout << "top()\t\t" << firstStack.top() << "\t"; firstStack.print(); cout << endl;

    //size line
    cout << "size()\t\t" << firstStack.size() << "\t"; firstStack.print(); cout << endl;

    //isEmpty line
    cout << "isEmpty()\t" << (firstStack.isEmpty() ? "true" : "false") << "\t"; firstStack.print(); cout << endl;

    return 0;
}
