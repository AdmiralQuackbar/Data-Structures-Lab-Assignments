#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int checkArraySort(string *A, int array_size);
int binarySearchAscendR(string *A, int array_size, string key, int lowerIndex);
int binarySearchDescendR(string *A, int array_size, string key, int lowerIndex);

int main()
{
    string word;
    string* pointer;
    int arraySize = 0;
    string key;
    ifstream wordsIn;

    //open txt document
    wordsIn.open("words_in.txt");

    //count the number of words in .txt
    wordsIn >> word;
    while(!(wordsIn.eof())) {
        wordsIn >> word;
        arraySize++;
    }

    //initialize pointer to string array of the size counted
    pointer = new string[arraySize];

    //reset the reading of the .txt to the beginning
    wordsIn.clear();
    wordsIn.seekg(wordsIn.beg);

    //take in the words into the array
    for(int counter = 0; counter < arraySize; counter++) {
        wordsIn >> pointer[counter];
    }  
    wordsIn.close();

    //check if the array of words is sorted
    if(checkArraySort(pointer, arraySize) == 1) {
        cout << "The array is sorted in ascending order!\n";
        cout << "Enter a key to search for in the array: ";
        cin >> key;
	//if ascending call binarysearch for ascending
        if(binarySearchAscendR(pointer, arraySize, key, 0) >= 0) {
            cout << "Found key " << key << " at index " << binarySearchAscendR(pointer, arraySize, key, 0) << "!\n";
        }
        else {
            cout << "The key " << key << " was not found in the array!\n";
        }
    }
    //if descending call binarysearch for descending
    else if(checkArraySort(pointer, arraySize) == -1) {
        cout << "The array is sorted in descending order!\n";
        cout << "Enter a key to search for in the array: ";
        cin >> key;
        if(binarySearchDescendR(pointer, arraySize, key, 0) >= 0) {
            cout << "Found key " << key << " at index " << binarySearchDescendR(pointer, arraySize, key, 0) << "!\n";
        }
        else {
            cout << "The key " << key << " was not found in the array!\n";
        }
    }
    else {
        cout << "The array is not sorted!\n";
    }
    
    return 0;
}

//checks if the array is sorted
int checkArraySort(string *A, int array_size)
{
    bool ascend = false;
    bool descend = false;
    //checks each element to see if a pair of adjacent elements are descending of ascending
    for(int counter = 1; counter < array_size; counter++) 
    {
	if(A[counter] > A[counter - 1]) {
	    ascend = true;
	}	
	else if(A[counter] < A[counter - 1]) {
	    descend = true;
	}
    }
    //array is ascending if only ascend bool is true
    if(ascend && !descend) {
	return 1;
    }
    //array is decending if only the descend bool is true
    else if(!ascend && descend) {
	return -1;
    }
    //if the ascend and descend bool are both true or false then it is not sorted
    else {
	return 0;
    }
}

//binary search for ascending array using recursion
int binarySearchAscendR(string *A, int array_size, string key, int lowerIndex)
{
    int upperIndex = array_size - 1;
    int midIndex = (lowerIndex + upperIndex)/2;
    while(upperIndex >= lowerIndex)
    {
        if(key == A[midIndex]) {
            return midIndex;
        }
        else if(key > A[midIndex]) {
            lowerIndex = midIndex + 1;
            return binarySearchAscendR(A, array_size, key, lowerIndex);
        }
        else {
            upperIndex = midIndex;
            return binarySearchAscendR(A, upperIndex, key, lowerIndex);
        }
    }
    return -1;
}

//binary search for descending array using recursion
int binarySearchDescendR(string *A, int array_size, string key, int lowerIndex)
{
    int upperIndex = array_size - 1;
    int midIndex = (lowerIndex + upperIndex)/2;
    while(upperIndex >= lowerIndex)
    {
        if(key == A[midIndex]) {
            return midIndex;
        }
        else if(key < A[midIndex]) {
            lowerIndex = midIndex + 1;
            return binarySearchDescendR(A, array_size, key, lowerIndex);
        }
        else {
            upperIndex = midIndex;
            return binarySearchDescendR(A, upperIndex, key, lowerIndex);
        }
    }
    return -1;
}
