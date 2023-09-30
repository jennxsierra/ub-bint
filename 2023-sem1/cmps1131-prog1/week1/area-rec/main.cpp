#include <iostream>

using namespace std;

int main()
{
    double length, width, area;

    cout << "Enter the length of the rectangle: ";
    cin >> length;

    cout << "Enter the width of the rectangle: ";
    cin >> width;

    area = length * width;

    cout << "The area of the rectangle is: " << area;

    return 0;
}