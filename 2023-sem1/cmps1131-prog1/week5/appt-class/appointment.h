#ifndef APPOINTMENT_H
#define APPOINTMENT_H


class Appointment
{
public:
    Appointment();

    int getday();
    int getmonth();
    int getyear();

    void setday(int);
    void setmonth(int);
    void setyear(int);

private:
    int day;
    int month;
    int year;
};

#endif // APPOINTMENT_H
