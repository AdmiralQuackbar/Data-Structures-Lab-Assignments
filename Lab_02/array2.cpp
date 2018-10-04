#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string phrase;
    int phraseSize;
    //prompt user to enter string
    cout << "Enter the string to reverse and have cases swapped for each character: ";
    getline(cin, phrase);
    //initilize phraseSize to the length of string
    phraseSize = phrase.length();
    //counterTwo represents the last index of the string
    int counterTwo = phraseSize;
    //delcare and initlize an char array to represent string
    char phraseArray[phraseSize + 1];
    //copy string into the char array
    strcpy(phraseArray, phrase.c_str());

    //swap the characters of the char array, starting from the corners of the array
    for(int counter = 0; counter < counterTwo; counter++) {
        char temp;
        temp = phraseArray[counterTwo];
        phraseArray[counterTwo] = phraseArray[counter];
        phraseArray[counter] = temp;
        counterTwo--;
    }

    //swap cases of letters using ASCII codes
    for(int counter = 0; counter <= phraseSize; counter++) {
        if(phraseArray[counter] >= 'A' && phraseArray[counter] <= 'Z') {
            phraseArray[counter] += 32;
        }
        else if(phraseArray[counter] >= 'a' && phraseArray[counter] <= 'z') {
            phraseArray[counter] -= 32;
        }
    }    

    //print out the reversed, case swapped char array
    cout << "The reverse of the string with cases swapped is: ";
    for(int counter = 0; counter <= phraseSize; counter++) {
        cout << phraseArray[counter];
    }
    cout << endl;
    
    return 0;
}
