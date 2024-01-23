#include "employee.h"
#include <iostream>
#include <string>
using namespace std;

Employee::Employee()
{

}

string Employee::getfirstName()
{
    return firstName;
}

string Employee::getlastName()
{
    return lastName;
}

int Employee::getmonthlySalary()
{
    return monthlySalary;
}

void Employee::setfirstName(string fName)
{
    firstName = fName;
}

void Employee::setlastName(string lName)
{
    lastName = lName;
}

void Employee::setmonthlySalary(int mSalary)
{
    if (mSalary < 0)
        {
            monthlySalary = 0;
        }
    else
        {
            monthlySalary = mSalary;
        }
}

void Employee::display()
{
    cout << "Employee Name: " << getfirstName() << " " << getlastName();
    cout << " \nMonthly Salary: $" << getmonthlySalary();
}

void Employee::employeeRaise(double raise)
{
    raise = (monthlySalary * 0.1) + monthlySalary;
}
