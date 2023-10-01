#include <iostream>

using namespace std;

void printOddorEven(int number);

int main() {

    printOddorEven(20);
    printOddorEven(11);

    return 0;
}

void printOddorEven(int number) {
    if (number % 2 == 0) {
        cout << "Number " << number << " is even" << endl;
    } else {
        cout << "Number " << number << " is odd" << endl;
    }
}
