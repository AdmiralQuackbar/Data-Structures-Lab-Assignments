#include <iostream>

using namespace std;

int main()
{
    int arraySize;
    int* array;
    int indexMax;	

    //prompt user to enter size of array
    cout << "Enter the size of the array: ";
    cin >> arraySize;
    //error message is invalid value is given
    if(arraySize < 1) {
	cout << "Error: You entered an invalid value for the array size!\n";
    }
    //if array size is valid, rest of program continues
    else 
    {
        //pointer array is initialized
        array = new int[arraySize];
	//prompt user to enter values for the array
	cout << "Enter the numbers in the array, seperated by a space, and press enter: ";
	for(int counter = 0; counter < arraySize; counter++) {
	    cin >> array[counter];
	}
	//selection sort, moves the maximum value to the front of the array	
	for(int counter = 0; counter < arraySize - 1; counter++) 
        {
	    int counterTwo;
	    indexMax = counter;
	    for(counterTwo = counter + 1; counterTwo < arraySize; counterTwo++) {
	        if(array[counterTwo] > array[indexMax]) {
		    indexMax = counterTwo;
		    }
	    }
		if(array[indexMax] > array[counter]) {
		    int temp = array[indexMax];
	    	    array[indexMax] = array[counter];
	    	    array[counter] = temp;
		}
	}
	//prints out sorted array
	cout << "The sorted array in descending is: ";
	for(int counter = 0; counter < arraySize; counter ++) {
	    cout << array[counter] << " ";	
	}
	cout << "\nThe algorithm selected the maximum value for traversing the array.\n";
    }
    return 0;
}
