#include <iostream>

using namespace std;

void sortArr(int *array, int arraySize, bool order);

int main()
{
    bool order;
    int* array;
    int arraySize;

    //prompts user to enter size of array
    cout << "Enter the size of the array: ";
    cin >> arraySize;

    //if value is invalid an error message appears
    if(arraySize < 1) {
	    cout << "Error: You entered an invalid value for the array size!\n";
    }
    //if value is valid rest of program continues
    else 
    {
            //sets pointer to an array of arraySize elements
	    array = new int[arraySize];
	    //prompts user to enter values for the array
	    cout << "Enter the numbers in the array, seperated by a space, and press enter: ";
	    for(int counter = 0; counter < arraySize; counter++) {
	        cin >> array[counter];
        }
        //aks user if they want the array to be in ascending or descending order
        cout << "Do you want to sort in ascending (0) or descending (1) order? ";
        cin >> order;

	//sort the array
        sortArr(array, arraySize, order);    

	//print out whether the array is sorted in descending or ascending order
        if(order) {
            cout << "This is the sorted array in descending order: ";
        }
        else {
            cout << "This is the sorted array in ascending order: ";
        }
	//print out sorted array
        for(int counter = 0; counter < arraySize; counter++) {
            cout << array[counter] << " ";
        }
        cout << endl;
    }
   return 0; 
}

//sorts array using insertion sort
void sortArr(int *array, int arraySize, bool order) 
{
    //sorts in ascending order
    if(!order) 
    {
        //starts with 2nd index until last index      
        for(int counter = 1; counter < arraySize; counter++) 
        {
            int max = array[counter];
            int counterTwo = counter - 1;
	    //compares every new index with the previous ones, making the max the highest index
            while((counterTwo >= 0) && (array[counterTwo] > max)) {
                    array[counterTwo + 1] = array[counterTwo];
                    counterTwo --;
            }
            array[counterTwo + 1] = max;
        }
    }
    //sorts in descending order
    else
    {
        //starts with 2nd index until last index
        for(int counter = 1; counter < arraySize; counter++) 
        {
            int min = array[counter];
            int counterTwo = counter - 1;
	    //compares every new index with the previous ones, making the minimum the highest index
            while((counterTwo >= 0) && (array[counterTwo] < min)) {
                    array[counterTwo + 1] = array[counterTwo];
                    counterTwo --;
            }
            array[counterTwo + 1] = min;
        }
    }
}
