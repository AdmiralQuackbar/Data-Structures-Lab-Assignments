#include <iostream>
#include <string>

using namespace std;

string repeatStr(string phrase, int repeat);

int main()
{
    int repeat = 1;
    string phrase;   

    //prompts user to enter a string
    cout << "Enter a string: ";
    getline(cin, phrase);

    //prompts user to enter the number of times to repeat
    cout << "Enter the number of times: ";
    cin >> repeat;

    //if repeat is greater than 0 it prints out the repeated string
    if(repeat > 0) {
        cout << repeatStr(phrase, repeat) << endl;
    }

    //if the repeat value is greater than 0 it will enter a loop to do the same process
    while(repeat > 0)
    {
        cout << "Enter a string: ";
        //refreshses the cin so it can prompt user to take in a string
	cin.clear();
        cin.ignore();

	getline(cin, phrase);

        cout << "Enter the number of times: ";
        cin >> repeat;
        
	if(repeat > 0) {
            cout << repeatStr(phrase, repeat) << endl;
	}
    }
    return 0;
}

//repeat string function
string repeatStr(string phrase, int repeat)
{
    //sets a temporary string to the string taken in
    string tempPhrase = phrase;
    //appends the temporary string to the string taken in for needed repeated number of times
    for(int counter = 0; counter < repeat - 1; counter++) {
        phrase += tempPhrase;
    }
    //returns the edited repeated string
    return phrase;
}
