#include <iostream>

using namespace std;

int main()
{
    double P, R, N, SI;

    cout << "Enter the Principal: ";
    cin >> P;

    cout << "Enter the Rate: ";
    cin >> R;

    cout << "Enter the Number of Years: ";
    cin >> N;

    SI = (P*N*R)/100;

    cout << "\nThe Simple Interest is $" << SI;

    return 0;
}