#include <iostream>

void while1();
void rewriteFor();
int while2();
int rewriteDoWhile();
void squareNumbers();

int main() {
    squareNumbers();
    return 0;
}

void while1() {
    int temp = 1;
    int i = 1;
    int y;

    std::cout << "Enter the value between 1-10 ";
    std::cin >> y;

    while (i < y)
    {
        temp = temp * i;
        i++;
    }
    std::cout << temp;
}

void rewriteFor() {
    int temp = 1;
    int y;

    std::cout << "Enter the value between 1-10 ";
    std::cin >> y;

    for (int i{1}; i < y; ++i) {
        temp = temp * i;
    }
    std::cout << temp;
}

int while2() {
    int sum = 0;
    int n = 10;

    while (n > 0) {
        sum = sum + n;
        --n;
    }
    return sum;
}

int rewriteDoWhile() {
    int sum = 0;
    int n = 10;

    do {
        sum = sum + n;
        --n;
    } while (n > 0);
    return sum;
}

void squareNumbers() {
    int number;

    while (true) {
        std::cout << "Enter a number (-1 to quit): ";
        std::cin >> number;

        if (number == -1) {
            break;
        }

        int square = number * number;
        std::cout << "The square of " << number << " is " << square << std::endl;
    }
}