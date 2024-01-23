#include <iostream>

using namespace std;

int main()
{
    double a, b, c, avg;

    cout << "Enter the first number: ";
    cin >> a;

    cout << "Enter the second number: ";
    cin >> b;

    cout << "Enter the third number: ";
    cin >> c;

    avg = (a+b+c)/3;

    cout << "\nThe average of the 3 given numbers is: " << avg;

    return 0;
}