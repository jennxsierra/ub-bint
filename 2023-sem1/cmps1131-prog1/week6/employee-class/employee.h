#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <string>
using namespace std;

class Employee
{
public:
    Employee();

    string getfirstName();
    string getlastName();
    int getmonthlySalary();

    void setfirstName(string);
    void setlastName(string);
    void setmonthlySalary(int);
    void display();
    void employeeRaise(double);

private:
    string firstName;
    string lastName;
    int monthlySalary;
    double raise;
};

#endif // EMPLOYEE_H
