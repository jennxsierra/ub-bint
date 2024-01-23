#include <iostream>

void printTriangleA();
void printTriangleB();

int main() {
    printTriangleA();
    std::cout << std::endl;
    printTriangleB();
}

void printTriangleA() {
    for (int i{1}; i <= 10; i++) {
        for (int j{1}; j <= i; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

void printTriangleB() {
    for (int i{0}; i <= 10; i++) {
        for (int j{10-i}; j > 0; j--) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}