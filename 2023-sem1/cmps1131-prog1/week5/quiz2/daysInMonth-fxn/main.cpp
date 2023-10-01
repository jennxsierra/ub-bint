#include <iostream>

using namespace std;

int daysInMonth(int month);

int main()
{
    int month;

    cout << "Enter the number of a month: ";
    cin >> month;

    cout << "This month has " << daysInMonth(month) << " days.";

    return 0;
}

int daysInMonth(int month)
{
    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        return 30;
    }
    else if (month == 2)
    {
        return 28;
    }
    else
    {
        return 31;
    }
}