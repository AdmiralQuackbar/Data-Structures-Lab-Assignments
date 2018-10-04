#include <iostream>

using namespace std;

int main()
{
    int arraySize;
    int targetValue = 0;    
    int lessThan;
    int greaterThan = 0;	

    do
    {
	//delcares pointer
	int* array;
	//prompts and ensures user enters a valid value for array size
        while(arraySize < 1) {
	    cout << "Enter the size of the array: ";
            cin >> arraySize;
 
	    if(arraySize < 1) {
                cout << "Error: You entered an invalid value for the array size!\n\n";
            }
	    //if user enters valid value, prompts user to enter values for array and stores it
	    else if(arraySize > 0) {
		//initializes pointer to point to an integer array
		array = new int[arraySize];
                cout << "Enter the numbers in the array, seperated by a space, and press enter: ";
                for(int counter = 0; counter < arraySize; counter++) {
		    cin >> array[counter];
		}
	    }
	}
	//prompts user to enter value for target value
	cout << "Enter the target value to check for array symmetry: ";
	cin >> targetValue;
	
	//resets value to 0 so it does not affect future arrays
	lessThan = 0;
	greaterThan = 0;
	
	//goes through array to check if the value in each array element is greater or lesser than target value
	for(int counter = 0; counter < arraySize; counter++) {
	    if(array[counter] < targetValue) {
		lessThan++;
	    }
	    else if(array[counter] > targetValue) {
		greaterThan++;
	    }
       	    else{};
	}
	//prints out telling user if the array is symmetric with respect to target value
	if(lessThan == greaterThan) {
	    cout << "This array IS symmetric with respect to " << targetValue << "!\n";
	}
	else {
	    cout << "This array IS NOT symmetric with respect to " << targetValue << "!\n";
	}
	//prints out the values in the array
	for(int counter = 0; counter < arraySize; counter++) {
	    cout << array[counter] << " ";
	}
	//deletes pointer to save memory space
	delete array;
	arraySize = 0;
	cout << "\n\n";
    } while(lessThan == greaterThan);//repeats process if the array was symmetric with target value

    return 0;
}	
