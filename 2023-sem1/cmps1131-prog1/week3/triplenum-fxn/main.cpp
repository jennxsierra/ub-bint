#include <iostream>
using namespace std;

double tripleOfNumber (double number);

int main ()
{
    cout << "Let's triple a number." << endl;
    cout << "--------------------------\n";
    double number;
    cout << "Enter a number: ";
    cin >> number;
    double triplenum = tripleOfNumber (number);
    cout << number << " tripled = " << triplenum << "\n\n";

    return 0;
}

double tripleOfNumber (double number)
{
    return number * 3;
}
