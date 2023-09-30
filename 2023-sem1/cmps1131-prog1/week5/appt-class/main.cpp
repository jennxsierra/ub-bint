#include <iostream>
#include "appointment.h"

using namespace std;

int main()
{
    Appointment Appt1;
    Appt1.setday(5);
    Appt1.setmonth(10);
    Appt1.setyear(2000);

    cout << "Your appointment is on day " << Appt1.getday() << ", month " << Appt1.getmonth() << ", year " << Appt1.getyear() << ".\n";

    return 0;
}
