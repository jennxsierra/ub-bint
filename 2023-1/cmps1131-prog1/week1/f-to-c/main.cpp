#include <iostream>

using namespace std;

int main()
{
    double F, C;

    cout << "Enter the temperature in Fahrenheit: ";
    cin >> F;

    C = (F - 32) * 5/9;

    cout << "\nThe temperature in Celsius is " << C << " degrees.";

    return 0;
}