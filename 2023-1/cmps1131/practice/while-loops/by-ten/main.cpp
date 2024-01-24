#include <iostream>

void printByTen(int, int);

int main() {
    printByTen(-50, 100);
    return 0;
}

void printByTen(int start, int end) {

    while (start <= end) {
        std::cout << start << " ";
        start += 10;
    }
}