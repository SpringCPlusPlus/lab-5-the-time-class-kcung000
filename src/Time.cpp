#include <iostream>
#include "../include/Time.h"
using namespace std;

// Overload the + operator
Time Time::operator+(const Time &other) const
{   
    int h=hours+other.hours;
    int m=minutes+other.minutes;
    h=(m/60)+h;
    m=m%60;
    Time t(h,m);
    return t;
}

// Overload the += operator
Time& Time::operator+=(const Time &other)
{   
    int h=hours+other.hours;
    int m=minutes+other.minutes;
    hours=(m/60)+h;
    minutes=m%60;
    return *this;
}

// Overload the < operator
bool Time::operator<(const Time &other) const
{
    int t=minutes+(hours*60);
    int ot=other.minutes+(other.hours*60);
    return t<ot;
}

// Overload the > operator
bool Time::operator>(const Time &other) const
{
    int t=minutes+(hours*60);
    int ot=other.minutes+(other.hours*60);
    return t>ot;
}

// Overload the == operator
bool Time::operator==(const Time &other) const
{
    int t=minutes+(hours*60);
    int ot=other.minutes+(other.hours*60);
    return (t-ot)==0;
}

// Overload the friend function operator<<
ostream &operator<<(ostream &os, const Time &tm)
{
    os << tm.getHours() << ":" << tm.getMinutes();
    return os;
}
