#include "Time.h"
#include <iostream>
#include <string>
#include <iomanip> 
#include <stdlib.h> 

using namespace std;

void print24Hour(Time time);
bool getTimeFromUser(Time& time);

int main()
{
    Time start;
    Time end;
    //prompt user to enter start time
    cout << "Enter the start time for the lecture (format is HH:MM:SS): ";
    if(getTimeFromUser(start) == true) {
        //if start time is valid, prompt user to enter end time
        cout << "Enter the end time for the lecture (format is HH:MM:SS): ";
        if(getTimeFromUser(end) == true) {
	    //if start time is valid print out the start and end time
            cout << "Lecture starts at ";
            print24Hour(start);
            cout << " and end at ";
            print24Hour(end);
            cout << endl;
        }
	//if end time is invalid print out error message
        else {
            cout << "The end time entered is invalid!\n";
        }
    }
    //if start time is invalid print out error message
    else {
        cout << "The start time entered is invalid!\n";
    }
    return 0;
}

//gets time from user and checks if valid
bool getTimeFromUser(Time& time)
{
    string input;
    //get time from user
    getline(cin, input);
    //get length of the string
    int length = input.length();
    //find position of 1st colon
    int firstColon = input.find(":", 1);
    //checks if the position of 1st colon is valid
    if(firstColon > 0 && firstColon < 3) {
        //get the numbers before the 1st colon
        string timeHour = input.substr(0, (0 + firstColon));
	//set the hours to those numbers
        time.setHour(atoi(timeHour.c_str()));
	//if hour value is not within 0-24 return false
        if(!(time.getHour() >= 0 && time.getHour() < 24)) {
            return false;
        }
	//find position of 2nd colon
        int secondColon = input.find(":", 3);
	//checks if the position of 2nd colon is valid
        if(secondColon > 2 && secondColon < 6) {
	    //get the numbers between the 1st and 2nd colon
            string timeMin = input.substr((firstColon + 1), (secondColon - firstColon));
	    //set the minutes to thsoe numbers
            time.setMin(atoi(timeMin.c_str()));
	    //if the minute value is not within 0-60 return false
            if(!(time.getMin() >= 0 && time.getMin() < 60)) {
                return false;
            }
	    //find the numbers after the 2nd colon
            string timeSec =input.substr((secondColon + 1), ((length - 1) - secondColon));
	    //set the seconds to those numbers
	    time.setSec(atoi(timeSec.c_str()));
	    //if he seconds value is not within 0-60 return false
            if(!(time.getSec() >= 0 && time.getSec() < 60)) {
                return false;
            }
        }
	//if position of 2nd colon is invalid return false
        else {
            return false;
        }
    }
    //if position of 1st colon is invalid return false
    else {
        return false;
    }
    //return true if the time goes through all the checks
    return true;
}

//prints out the time in 24 hour format
void print24Hour(Time time)
{
    //allows for single digit inputs
    cout << setfill('0') << setw (2) << time.getHour() << ":";
    cout << setfill('0') << setw (2) << time.getMin() << ":";
    cout << setfill('0') << setw (2) << time.getSec();
}
