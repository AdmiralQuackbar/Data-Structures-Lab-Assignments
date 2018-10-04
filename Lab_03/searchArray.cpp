#include <iostream>

using namespace std;

int main()
{
    int arraySize;
    int key;
    int* array;
    int index;
    bool found = false;

    //prompt user to enter array size
    cout << "Enter the size of the array: ";
    cin >> arraySize;
    //prints error message if array size is invalid
    if(arraySize < 1) {
	cout << "Error: You entered an invalid value for the array size!\n";
    }
    //if valid, rest of code continues
    else if(arraySize > 0) 
    {
        //initialize pointer to an int array
	array = new int[arraySize];
	//prompt user to fill in array
        cout << "Enter the numbers in the array, seperated by a space, and press enter: ";
	for(int counter = 0; counter < arraySize; counter++) {
	    cin >> array[counter];
	}
	//prompt user to enter a value to search for
        cout << "Enter the key to search in the array: ";
	cin >> key;

	//checks if key is in the array, stopping if found
	for(index = 0; index < arraySize; index++) {
	    if(key == array[index]) {
		found = true;
		break;
	    }
	}
	//if key is found, print out at which index it was found as well as how many checks it took
	if(found) {
	    cout << "Found value " << key << " at index " << index <<  ", taking " << index + 1 << " checks!\n";
	    //prints out if it was a worst or best case scenario
	    if(index == 0) {
		cout << "We ran into the best-case scenario!\n";
	    }
	    else if(index == (arraySize - 1)) {
		cout << "We ran into the worst-case scenario!\n";
	    }
	}
	//if key was not found, message will be printed
	else {
	    cout << "The value " << key << " was not found in the array!\n";
	}
    }
    return 0;
}
