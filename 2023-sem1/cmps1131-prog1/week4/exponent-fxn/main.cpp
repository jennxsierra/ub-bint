#include <iostream>

using namespace std;

int power(int base, int exponent);

int main()
{
    cout << "The answer for 6^5 is " << power(6,5);

    return 0;
}

int power(int base, int exponent) {
    int result{1};
    for(int i{1}; i <= exponent; ++i) {
        result *= base;
    }
    return result;
}