#include <iostream>

using namespace std;

int main()
{
int hours;
double rate;
double wage;

cout << "This program will calculate the wage of an employee.\n";

cout << "\nPlease enter the hours worked by the employee: ";
cin >> hours;

cout << "Please enter the hourly rate of the employee: ";
cin >> rate;

wage = hours * rate;

cout << "\nThe employee's wage is $" << wage;

return 0;
}