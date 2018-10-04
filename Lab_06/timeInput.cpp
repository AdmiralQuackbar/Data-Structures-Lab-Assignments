#include <iostream>
#include <string>
#include <iomanip>  
#include <stdlib.h>

using namespace std;

//Time struct
struct Time 
{
    int hour;
    int min;
    int sec;
}start, end;

//functions that take in Time structure
bool getTimeFromUser(Time& time);
void print24Hour(Time time);

int main()
{
    //prompt user to enter start time
    cout << "Enter the start time for the lecture (format is HH:MM:SS): ";
    //checks if time is valid
    if(getTimeFromUser(start) == true) {
	//prompt user to enter end time
        cout << "Enter the end time for the lecture (format is HH:MM:SS): ";
	//checks if time is valid, if so print out the start and end time for lecture
        if(getTimeFromUser(end) == true) {
            cout << "Lecture starts at ";
            print24Hour(start);
            cout << " and end at ";
            print24Hour(end);
            cout << endl;
        }
	//error if end time is invalid
        else {
            cout << "The end time entered is invalid!\n";
        }
    }
    //error if start time is invalid
    else {
        cout << "The start time entered is invalid!\n";
    }
    return 0;
}

//prompts user to enter time and returns if it is valid
bool getTimeFromUser(Time& time)
{
    //intake time input from user
    string input;
    getline(cin, input);
    //record length of the input
    int length = input.length();
    //get position of 1st :
    int firstColon = input.find(":", 1);
    //checks if the 1st : is in a valid spot
    if(firstColon > 0 && firstColon < 3) {
	//get the numbers before the 1st : for hours
        string timeHour = input.substr(0, (0 + firstColon));
        time.hour = atoi(timeHour.c_str());
	//if hour value is not valid return false
        if(!(time.hour >= 0 && time.hour < 24)) {
            return false;
        }
        //get position of 2nd :
        int secondColon = input.find(":", 3);
	//checks if position of 2nd : is valid
        if(secondColon > 2 && secondColon < 6) {
	    //get the numbers between the 1st and 2nd :'s
            string timeMin = input.substr((firstColon + 1), (secondColon - firstColon));
            time.min = atoi(timeMin.c_str());
	    //if the minute value is not valid return false
            if(!(time.min >= 0 && time.min < 60)) {
                return false;
            }
	    //get the numbers after the 2nd : for seconds
            string timeSec = input.substr((secondColon + 1), ((length - 1) - secondColon));
            time.sec = atoi(timeSec.c_str());
	    //if the seconds value is not valid return false
            if(!(time.sec >= 0 && time.sec < 60)) {
                return false;
            }
        }
	//if 2nd : is not in valid spot return false
        else {
            return false;
        }
    }
    //if first : is not in valid spot return false
    else {
        return false;
    }
    //return true if everything goes through
    return true;
}

//prints out 24hour time, filling in 0 for single digits numbers
void print24Hour(Time time)
{
    cout << setfill('0') << setw (2);
    cout << time.hour << ":";
    cout << setfill('0') << setw (2);
    cout << time.min << ":";
    cout << setfill('0') << setw (2);
    cout << time.sec;
}
