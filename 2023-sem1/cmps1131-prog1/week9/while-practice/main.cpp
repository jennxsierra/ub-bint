#include <iostream>

void printOnetoNine();
void printFourtoZero();
void printOnetoNineteen();

int main() {
    printOnetoNine();
    std::cout << std::endl;
    printFourtoZero();
    std::cout << std::endl;
    printOnetoNineteen();
    std::cout << std::endl;

    return 0;
}

void printOnetoNine() {
    int y = 1;
    while (y <= 9) {
        std::cout << y;
        y++;
    }
}

void printFourtoZero() {
    int num = 5;
    while (num != 0) {
        num -= 1;
        std::cout << num;
    }
}

void printOnetoNineteen() {
    int y{1};
    while (y <= 19) {
        if (y % 2 == 0) {
            std::cout << y;
            if (y % 6 == 0) {
                std::cout << '\n';
            } else {
                std::cout << ' ';
            }
        }
        ++y;
    }
}