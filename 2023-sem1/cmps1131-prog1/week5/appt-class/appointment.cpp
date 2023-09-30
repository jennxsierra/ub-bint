#include "appointment.h"

Appointment::Appointment()
{

}

int Appointment::getday()
{
    return day;
}

int Appointment::getmonth()
{
    return month;
}

int Appointment::getyear()
{
    return year;
}

void Appointment::setday(int a)
{
    if (a < 1 || 31 < a)
    {
        day = 0;
    }
    else
    {
        day = a;
    }
}

void Appointment::setmonth(int b)
{
    if (b < 1 || 12 < b)
    {
        month = 0;
    }
    else
    {
        month = b;
    }
}

void Appointment::setyear(int c)
{
    if (c < 0)
    {
        year = 0;
    }
    else
    {
    year = c;
    }
}
