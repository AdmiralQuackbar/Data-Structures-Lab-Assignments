#include "Time.h"

//default constructor
Time::Time() 
{
    hours = 0;
    minutes  = 0;
    seconds = 0;
}

//overloaded constructor
Time::Time(int h, int m, int s) 
{
    hours = h;
    minutes  = m;
    seconds = s;
}

//destructor
Time::~Time(){}

//hour getter
int Time::getHour() {
    return hours;
}

//minute getter
int Time::getMin(){
    return minutes;
}

//second getter
int Time::getSec() {
    return seconds;
}

//hour setter
void Time::setHour(int h) {
    hours = h;
}

//minute setter
void Time::setMin(int m) {
    minutes = m;
}

//second setter
void Time::setSec(int s) {
    seconds = s;
}
