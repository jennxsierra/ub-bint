#include <iostream>

const int arrSize = 5;
int arr[arrSize] = {11, 18, 64, 5, 33};

void printArray(int [], int);
int findRange(const int [], int);

int main() {
    std::cout << "The array currently contains these values:" << std::endl;
    printArray(arr, arrSize);
    std::cout << std::endl;

    std::cout << "\nThe array's range is ";
    int result = findRange(arr, arrSize);
    std::cout << result << std::endl;

    return 0;
}

void printArray(int array[], int size) {
    for(int i{0}; i < size; i++) {
        std::cout << array[i] << " ";
    }
}

int findRange(const int array[], int size) {
    int minVal = array[0];
    int maxVal = array[0];

    for(int i = 1; i < size; i++) {
        if(array[i] < minVal) {
            minVal = array[i];
        }
        if(array[i] > maxVal) {
            maxVal = array[i];
        }
    }

    return maxVal - minVal + 1;
}