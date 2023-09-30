#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double a, b, c, s, area;

    cout << "Enter the value of the first side of the triangle: ";
    cin >> a;

    cout << "Enter the value of the second side of the triangle: ";
    cin >> b;

    cout << "Enter the value of the third side of the triangle: ";
    cin >> c;

    s = (a+b+c)/2;

    area = sqrt(s*(s-a)*(s-b)*(s-c));


    cout << "The area of the triangle is: " << area;


    return 0;
}