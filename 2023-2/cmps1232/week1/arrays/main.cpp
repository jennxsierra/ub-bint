#include <iostream>

int main() {
    int array[10] = {0};
    int size = 10;

    for(int i{0}; i < size; i++) {
        std::cout << "Enter a number: ";
        std::cin >> array[i];
    }

    int sum = 0;
    for (int i{0}; i < size; i++) {
        sum += array[i];
    }

    int avg = sum/size;
    std::cout << "The average of the array is equal to " << avg;

    return 0;
}

