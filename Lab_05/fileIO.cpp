#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int checkArray(string *A, int array_size);

int main()
{
    string word;
    string* pointer;
    int arraySize = 0;
    ifstream wordsIn;
    ofstream wordsOut;

    //open .txt document
    wordsIn.open("words_in.txt");

    //counts the number of words in the .txt
    wordsIn >> word;    
    while(!(wordsIn.eof())) {
        wordsIn >> word;
        arraySize++;
    }

    //initialize pointer to a string array of the size counted
    pointer = new string[arraySize];

    wordsIn.clear();
    wordsIn.seekg(wordsIn.beg);

    //open the out.txt
    wordsOut.open("words_out.txt");

    //reads each words into the array and prints it out simultaneously
    for(int counter = 0; counter < arraySize; counter++) {
        wordsIn >> pointer[counter];
	wordsOut << pointer[counter] << endl;
    }  
    wordsIn.close();
    wordsOut.close();

    //checks if array is sorted
    if(checkArray(pointer, arraySize) == 1){
        cout << "The array is sorted in ascending order!\n";
    }
    else if(checkArray(pointer, arraySize) == -1) {
        cout << "The array is sorted in descending order!\n";
    }
    else {
        cout << "The array is not sorted!\n";
    }
    
    return 0;
}

//checks if array is sorted
int checkArray(string *A, int array_size)
{
    bool ascend = false;
    bool descend = false;
    for(int counter = 1; counter < array_size; counter++) 
    {
	if(A[counter] > A[counter - 1]) {
	    ascend = true;
	}	
	else if(A[counter] < A[counter - 1]) {
	    descend = true;
	}
    }

    if(ascend && !descend) {
	return 1;
    }
    else if(!ascend && descend) {
	return -1;
    }
    else {
	return 0;
    }
}
