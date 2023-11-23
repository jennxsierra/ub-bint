#include <iostream>

int findLargest(int);
void digit_to_name(int);

int main() {
    int numberOfInputs = 0;
    std::cout << "Enter number of integers you want to input: ";
    std::cin >> numberOfInputs;
    int result = findLargest(numberOfInputs);
    std::cout << "The largest number entered is " << result;

    return 0;
}

int findLargest(int x) {
    int largest = -999999999;
    int input = 0;

    for (int i = 0; i < x; i++) {
        std::cout << "Enter an integer: ";
        std::cin >> input;
        if (input > largest) {
            largest = input;
        }
    }
    return largest;
}

void digit_to_name(int x) {
    switch (x) {
        case 1:
            std::cout << "one" << std::endl;
            break;
        case 2:
            std::cout << "two" << std::endl;
            break;
        case 3:
            std::cout << "three" << std::endl;
            break;
        case 4:
            std::cout << "four" << std::endl;
            break;
        case 5:
            std::cout << "five" << std::endl;
            break;
        case 6:
            std::cout << "six" << std::endl;
            break;
        case 7:
            std::cout << "seven" << std::endl;
            break;
        case 8:
            std::cout << "eight" << std::endl;
            break;
        case 9:
            std::cout << "nine" << std::endl;
            break;
        default:
            std::cout << "Digit error" << std::endl;
            break;
    }
}

