#include <iostream>

using namespace std;

int main ()
{
    double a, b;

    cout << "Enter the first number: ";
    cin >> a;

    cout << "Enter the second number: ";
    cin >> b;

    if (a > b)
    {
        cout << "\nThe first number if greater.";
    }
    else
    {
        cout << "\nThe second number is greater.";
    }

    return 0;
}