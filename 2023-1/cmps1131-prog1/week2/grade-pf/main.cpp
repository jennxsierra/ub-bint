#include <iostream>

using namespace std;

int main ()
{
    int grade;

    cout << "Enter the student's average: ";
    cin >> grade;

    if (grade >= 70)
    {
        cout << "Your grade is P.";
    }
    else
    {
        cout << "Your grade is F.";
    }

    return 0;
}