#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int checkArraySort(string *A, int array_size);
int binarySearchAscendL(string *A, int array_size, string key);
int binarySearchDescendL(string *A, int array_size, string key);

int main()
{
    string word;
    string* pointer;
    int arraySize = 0;
    string key;
    ifstream wordsIn;
    //open .txt document
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

    //check if the array is sorted
    if(checkArraySort(pointer, arraySize) == 1) {
        cout << "The array is sorted in ascending order!\n";
        cout << "Enter a key to search for in the array: ";
        cin >> key;
	//if ascending call binary search for ascending
        if(binarySearchAscendL(pointer, arraySize, key) >= 0) {
            cout << "Found key " << key << " at index " << binarySearchAscendL(pointer, arraySize, key) << "!\n";
        }
        else {
            cout << "The key " << key << " was not found in the array!\n";
        }
    }
    //if descending call binary search for descending
    else if(checkArraySort(pointer, arraySize) == -1) {
        cout << "The array is sorted in descending order!\n";
        cout << "Enter a key to search for in the array: ";
        cin >> key;
        if(binarySearchDescendL(pointer, arraySize, key) >= 0) {
            cout << "Found key " << key << " at index " << binarySearchDescendL(pointer, arraySize, key) << "!\n";
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
    //checks each pair of adjacent element to see if they are descending or ascending
    for(int counter = 1; counter < array_size; counter++) 
    {
	if(A[counter] > A[counter - 1]) {
	    ascend = true;
	}	
	else if(A[counter] < A[counter - 1]) {
	    descend = true;
	}
    }
    //array is ascending if only the ascend bool is true
    if(ascend && !descend) {
	return 1;
    }
    //array is descending if only the descend bool is true
    else if(!ascend && descend) {
	return -1;
    }
    //if the descend and ascend bool are both true or false, then its not sorted
    else {
	return 0;
    }
}

//binary search for ascending using for loop
int binarySearchAscendL(string *A, int array_size, string key)
{
    int upperIndex = array_size - 1;
    for(int lowerIndex = 0; lowerIndex <= upperIndex;)
    {
        int midIndex = (lowerIndex + upperIndex)/2;
        if(key == A[midIndex]) {
            return midIndex;
        }
        else if(key > A[midIndex]) {
            lowerIndex = midIndex + 1;
        }
        else {
            upperIndex = midIndex - 1;
        }
    }
    return -1;
}

//binary search for descending using for loop
int binarySearchDescendL(string *A, int array_size, string key)
{
    int upperIndex = array_size - 1;
    for(int lowerIndex = 0; lowerIndex <= upperIndex;)
    {
        int midIndex = (lowerIndex + upperIndex)/2;
        if(key == A[midIndex]) {
            return midIndex;
        }
        else if(key < A[midIndex]) {
            lowerIndex = midIndex + 1;
        }
        else {
            upperIndex = midIndex - 1;
        }
    }
    return -1;
}
