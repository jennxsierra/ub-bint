#include <iostream>

using namespace std;

void fizzBuzz(int num);

int main() {
    cout << "Output of fizzBuzz(10): ";
    fizzBuzz(10);

    cout << "\nOutput of fizzBuzz(15): ";
    fizzBuzz(15);

    return 0;
}

void fizzBuzz(int num) {
    if (num % 3 == 0) {
        cout << "Fizz";
    } else {
        cout << num;
    }
}