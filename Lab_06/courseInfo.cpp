#include <iostream>
#include <string>
#include <iomanip>  
#include <stdlib.h>
#include <fstream>

using namespace std;

struct Time 
{
    int hour;
    int min;
    int sec;
};

struct Course
{
    string name;
    int credits;
    bool majorRequirement;
    double avgGrade;
    string days;
    Time startTime;
    Time endTime;

}course;

bool getTimeFromUser(Time& time, string clock);
void print24Hour(Time& time);

int main()
{
    string word;   
    ifstream courseIn;
    courseIn.open("in.txt");

    int numOfCourses;
    courseIn >> numOfCourses;     

    cout << "-------------------\n" << "SCHEDULE OF STUDENT\n" << "-------------------\n";
    for(int counter = 0; counter < numOfCourses; counter++) 
    {
        courseIn >> course.name;
        cout << "Course " << counter + 1 << ": " << course.name << endl; 

	courseIn >> course.credits;
	courseIn >> course.majorRequirement;
	if(course.majorRequirement) {
	    cout << "Note: This course is a major requirement!\n";
	}
	else {
	    cout << "Note: This course is not a major requirement.\n";
	}

	cout << "Credits: " << course.credits << endl;

	courseIn >> course.avgGrade;
	courseIn >> course.days;
	cout <<  "Days of Lectures: " << course.days << endl;

	string clock;
	courseIn >> clock;
	getTimeFromUser(course.startTime, clock);
	courseIn >> clock;
	getTimeFromUser(course.endTime, clock);
	cout << "Lecture Time:  ";
	print24Hour(course.startTime);
	cout << "-";
	print24Hour(course.endTime);
	cout << endl;

	cout << "Stat: On average students get " << course.avgGrade << "% in this course.\n";

        cout << "-------------------\n";
    }     
    return 0;
}

bool getTimeFromUser(Time& time, string clock)
{
    string input = clock;
    int length = input.length();
    int firstColon = input.find(":", 1);
    if(firstColon > 0 && firstColon < 3) {
        string timeHour = input.substr(0, (0 + firstColon));
        time.hour = atoi(timeHour.c_str());
        if(!(time.hour >= 0 && time.hour < 24)) {
            return false;
        }
        int secondColon = input.find(":", 3);
        if(secondColon > 2 && secondColon < 6) {
            string timeMin = input.substr((firstColon + 1), (secondColon - firstColon));
            time.min = atoi(timeMin.c_str());
            if(!(time.min >= 0 && time.min < 60)) {
                return false;
            }
            string timeSec = input.substr((secondColon + 1), ((length - 1) - secondColon));
            time.sec = atoi(timeSec.c_str());
            if(!(time.sec >= 0 && time.sec < 60)) {
                return false;
            }
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
    return true;
}

void print24Hour(Time& time)
{
    bool PM;
    if(time.hour > 12) {
	time.hour = time.hour - 12;
	PM = true;
    }
    cout << time.hour << ":";
    cout << setfill('0') << setw (2);
    cout << time.min << ":";
    cout << setfill('0') << setw (2);
    cout << time.sec;
    if(PM) {
        cout << "PM";
    }
    else {
        cout << "AM";
    }
}
