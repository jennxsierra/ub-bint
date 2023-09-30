#include <iostream>
#include <string>
#include "employee.h"

using namespace std;

int main()
{
    Employee Employee1;
    Employee1.setfirstName("Jennessa");
    Employee1.setlastName("Sierra");
    Employee1.setmonthlySalary(2000);
    Employee1.display();
    cout << "\n\n";
    cout << "The employee's salary was raised to $" << Employee1.employeeRaise(raise);

    Employee Employee2;
    Employee2.setfirstName("Andres");
    Employee2.setlastName("Hung");
    Employee2.setmonthlySalary(1500);
    Employee2.display();
    cout << "\n\n";

    return 0;
}
