#include <iostream>

using namespace std;

int main() 
{
    int x;

    do
    {
        cout << "Enter a positive integer between [1-100]: ";
        cin >> x;

        if(x < 0) {
	cout << "Invalid" << endl;
	}

	else if(x > 100) {
	cout << "Out of range" << endl;
        }		

	else if(x > 0 && x < 101){
	    bool isPrime = true;

	    for(int y = x-1; y > 1; y--) {
	        if(x % y == 0) {
	   	    isPrime = false;
		}
	    }
	    if(!isPrime || x == 1) {
	        cout << "Not Prime" << endl;
	    }

	    else {
	        cout << "Prime" << endl;
	    }	
	} 
	else {};
    } while(x != 0);
    return 0;
}
