#include <iostream>

using namespace std;

int main()
{
    int x;

    while(x > -1) {
        cout << "Enter a positive integer: ";
        cin >> x;
        if(x % 2 == 1){
	    cout << "Odd" << endl;
	}  
	else if(x % 2 == 0) {
	    cout << "Even" << endl;
	}
	else {};
    }
    return 0;
}
