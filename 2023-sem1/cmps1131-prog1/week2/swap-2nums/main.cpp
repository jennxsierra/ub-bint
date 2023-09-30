#include <iostream>

using namespace std;

int main()
{
    double a, b, c;

    cout << "Enter the value of A: ";
    cin >> a;

    cout << "Enter the value of B: ";
    cin >> b;

    c = a;
    a = b;
    b = c;

    cout << "\nThe values of A & B after swapping are:";
    cout << "\nA = " << a;
    cout << "\nB = " << b;

    return 0;
}