#include "Stack.h"
#include "LinkedList.h"
#include <iostream>

using namespace std;

int main()
{
    //create stack object of type char
    Stack<char> firstStack;

    //tabel labels
    cout << "Function Call\tOutput\tStack Contents\n";

    //tables row function calls/print outs
    cout << "isEmpty()\t" << (firstStack.isEmpty() ? "true" : "false") << "\t"; firstStack.print(); cout << endl;
    
    cout << "push(A)\t\t"; firstStack.push('A'); cout << "\t"; firstStack.print(); cout << endl;
    
    cout << "push(Y)\t\t"; firstStack.push('Y'); cout << "\t"; firstStack.print(); cout << endl;
   
    cout << "size()\t\t" << firstStack.size() << "\t"; firstStack.print(); cout << endl;
   
    cout << "pop()\t\t" << firstStack.pop() << "\t"; firstStack.print(); cout << endl;
    
    cout << "isEmpty()\t" << (firstStack.isEmpty() ? "true" : "false") << "\t"; firstStack.print(); cout << endl;
    
    cout << "push(D)\t\t"; firstStack.push('D'); cout << "\t"; firstStack.print(); cout << endl;
   
    cout << "top()\t\t" << firstStack.top() << "\t"; firstStack.print(); cout << endl;
   
    cout << "push(T)\t\t"; firstStack.push('T'); cout << "\t"; firstStack.print(); cout << endl;
    
    cout << "pop()\t\t" << firstStack.pop() << "\t"; firstStack.print(); cout << endl;

    return 0;
}
