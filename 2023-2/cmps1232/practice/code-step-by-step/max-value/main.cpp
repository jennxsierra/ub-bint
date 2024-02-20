#include <iostream>

const int arrSize = 6;
int arr[arrSize] = {17, 7, -1, 26, 3, 9};

void printArray(int [], int);
int maxValue(const int [], int);

int main() {
    std::cout << "The array currently contains these values:" << std::endl;
    printArray(arr, arrSize);
    std::cout << std::endl;

    std::cout << "\nThe maximum value in this array is ";
    int result = maxValue(arr, arrSize);
    std::cout << result << std::endl;

    return 0;
}

void printArray(int array[], int size) {
    for(int i{0}; i < size; i++) {
        std::cout << array[i] << " ";
    }
}

int maxValue(const int array[], int size) {
    int maxVal = array[0];

    for(int i{0}; i < size; i++) {
        if(array[i] > maxVal) {
            maxVal = array[i];
        }
    }
    return maxVal;
}