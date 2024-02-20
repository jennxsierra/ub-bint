#include <iostream>

const int arrSize = 10;
int list[arrSize] = {42, 7, -9, 14, 8, 39, 42, 8, 19, 0};

void printArray(int [], int);
int indexOf(const int [], int, int);


int main() {
    std::cout << "The array currently contains these values:" << std::endl;
    printArray(list, arrSize);
    std::cout << std::endl;

    std::cout << "\nThe index of the value 8 in this array is ";
    int result = indexOf(list, arrSize, 8);
    std::cout << result << std::endl;

    std::cout << "The index of the value 2 in this array is ";
    result = indexOf(list, arrSize, 2);
    std::cout << result << std::endl;

    return 0;
}

void printArray(int array[], int size) {
    for(int i{0}; i < size; i++) {
        std::cout << array[i] << " ";
    }
}

int indexOf(const int array[], int size, int target) {
    for(int i = 0; i < size; i++) {
        if(array[i] == target) {
            return i;
        }
    }
    return -1;
}