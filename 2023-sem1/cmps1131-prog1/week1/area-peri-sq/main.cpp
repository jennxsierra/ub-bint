#include <iostream>

using namespace std;

int main()
{
    double length, area, perimeter;

    cout << "Enter the length of the square: ";
    cin >> length;

    area = length * length;

    perimeter = length * 4;

    cout << "\nThe area of the square is: " << area;
    cout << "\nThe perimeter of the square is: " << perimeter;

    return 0;
}