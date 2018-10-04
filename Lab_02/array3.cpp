#include <iostream>
using namespace std;

int main()
{
    int size;
    int squareNum = 0;

    //prompt user to enter size of 2D array
    cout << "Enter the size of a 2D array: ";
    cin >> size;

    //checks to make ensure user inputs a valid value
    if(size > 10) {
      cout << "Error: your array is too large! Enter a number between 1 and 10 (inclusive).\n";
    }
    else if(size < 1) {
        cout << "ERROR: you entered an invalid value for the array size!\n";    
    }
    //rest of program will continue if value is valid
    else
    {
        //declare and initlize 2d array
        int array[size][size];
	//prompt user to enter the array elements row by row
        for(int row = 0; row < size; row++) {
            cout << "Enter the array elements in row " << row + 1 << " separated by spaces, and press enter: ";
            for(int column = 0; column < size; column++) {
                cin >> array[row][column];
            }
        }   
        //goes through every element in the array
        for(int row = 0; row < size; row++) {
            for(int column = 0; column < size; column++) {
	        //if the element value is greater than 0 and is a perfect square, the counter squareNum increases
	        if(array[row][column] > 0) {
                    for(int counter = 0; counter <= array[row][column]; counter++) {
                        if((counter * counter) == array[row][column]) {
                            squareNum++;
                        }
                    }
                }
            }
        }  
	//outputs the number of square numbers
        if(squareNum == (size * size)) {
            cout << "All are square numbers!\n";
        }
        else if(squareNum == 1) {
            cout << "There is only 1 square number!\n";
        }
        else {
            cout << "There are " << squareNum << " square numbers!\n";
        }
    }
    
    return 0;
}
