#include <iostream>

using namespace std;

void sortArr(int *array, int arraySize, bool order);

int main()
{
    bool order;
    int* array;
    int arraySize;

    //prompt user to enter size of array
    cout << "Enter the size of the array: ";
    cin >> arraySize;

    //if the value is invalid an error message appears
    if(arraySize < 1) {
	    cout << "Error: You entered an invalid value for the array size!\n";
    }
    //if value is valid, the rest of program continues
    else 
    {
            //sets pointer to an array of arraySize elements
	    array = new int[arraySize];
	    //prompts user to enter values for the array
	    cout << "Enter the numbers in the array, seperated by a space, and press enter: ";
	    for(int counter = 0; counter < arraySize; counter++) {
	        cin >> array[counter];
        }    
        //asks user if the user wants the array sorted in descending or ascending order
	cout << "Do you want to sort in ascending (0) or descending (1) order? ";
        cin >> order;

	//sorts the array
        sortArr(array, arraySize, order);    

	//prints out if the array is ascending or descending
        if(order) {
            cout << "This is the sorted array in descending order: ";
        }
        else {
            cout << "This is the sorted array in ascending order: ";
        }
        //prints out the sorted array
        for(int counter = 0; counter < arraySize; counter++) {
            cout << array[counter] << " ";
        }
	cout << endl;
    }
   return 0; 
}

//sorts array using selection sort
void sortArr(int *array, int arraySize, bool order) 
{
    //sorts in ascending order
    if(!order) 
    {
        //looks for the minimum arraySize - 1 times      
        for(int counter = 0; counter < arraySize - 1; counter++) 
        {
            int counterTwo;
	    int indexMin = counter;
	    //goes thorugh every index except for the sorted indexes to find the minimum
            for(counterTwo = counter + 1; counterTwo < arraySize; counterTwo++) {
                if(array[counterTwo] < array[indexMin]) {
                indexMin = counterTwo;
                }
            }
	    //swaps the minimum with the first unsorted index
            if(array[indexMin] < array[counter]) {
                int temp = array[indexMin];
                array[indexMin] = array[counter];
                array[counter] = temp;
            }
        }
    }
    //sorts in descending order
    else 
    {
        //look for the minimum arraySize - 1 times
        for(int counter = 0; counter < arraySize - 1; counter++) 
        {
            int counterTwo;
            int indexMax = counter;
	    //goes through every index except for the sorted indexes to find the max
            for(counterTwo = counter + 1; counterTwo < arraySize; counterTwo++) {
                if(array[counterTwo] > array[indexMax]) {
                    indexMax = counterTwo;
                }
            }
	    //swaps the max with the first unsorted index
            if(array[indexMax] > array[counter]) {
                int temp = array[indexMax];
                array[indexMax] = array[counter];
                array[counter] = temp;
            }
        }
    }
}
