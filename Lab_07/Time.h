#ifndef TIME_H
#define TIME_H

class Time
{
    private:
        int hours;
        int minutes;
        int seconds;

    public:
        Time();
        Time(int h, int m, int s);
        ~Time();
        int getHour();
        int getMin();
        int getSec();
        void setHour(int h);
        void setMin(int m);
        void setSec(int s);
};

#endif