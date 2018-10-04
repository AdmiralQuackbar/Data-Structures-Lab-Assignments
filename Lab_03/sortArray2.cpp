#include <iostream>

using namespace std;

int main()
{
    int arraySize;
    int* array;
    int indexMin;	
    int swaps;

    //prompt user to enter size of array
    cout << "Enter the size of the array: ";
    cin >> arraySize;
    //if value is invalid print out error message
    if(arraySize < 1) {
	cout << "Error: You entered an invalid value for the array size!\n";
    }
    //if value is valid, continue with rest of program
    else 
    {
        //initiliaze pointer to array
        array = new int[arraySize];
	//prompt user to enter values for the array
	cout << "Enter the numbers in the array, seperated by a space, and press enter: ";
	for(int counter = 0; counter < arraySize; counter++) {
	    cin >> array[counter];
	}
	//selection sort, using minimum value to move to the front of the array	
	for(int counter = 0; counter < arraySize - 1; counter++) 
        {
	    int counterTwo;
	    indexMin = counter;
	    for(counterTwo = counter + 1; counterTwo < arraySize; counterTwo++) {
	        if(array[counterTwo] < array[indexMin]) {
		    indexMin = counterTwo;
            }
	    }
		if(array[indexMin] < array[counter]) {
		    int temp = array[indexMin];
		    array[indexMin] = array[counter];
		    array[counter] = temp;
		    swaps++;
		}
	}
	//print out sorted array
	cout << "The sorted array in ascending is: ";
	for(int counter = 0; counter < arraySize; counter ++) {
	    cout << array[counter] << " ";	
	}
	//print out the number of swaps
	cout << "\nThe algorithm selected the minimum value for traversing the array. It took " << swaps << " swaps to sort the array.\n";
    }
    return 0;
}
