#include <iostream>

const int arrSize {10};
int arr[arrSize] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

void printArray(const int [], int); //Prints the array
void reverseArray(int [], int); //Reverses the array
void findMax(const int [], int); //Finds the max value in the array
void findMin(const int [], int); //Finds the min value in the array
void findSum(const int [], int); //Finds the sum of the values in the array
void findAvg(const int [], int); //Finds the average of the values in the array
void sortArray(int [], int); //Sorts the array in ascending order

int main() {
    std::cout << "The array contains the following numbers: " << std::endl;
    printArray(arr, arrSize);
    std::cout << "\n";

    std::cout << "After passing the array through the function reverseArray, "
                 "the order is now: " << std::endl;
    reverseArray(arr, arrSize);
    printArray(arr, arrSize);
    std::cout << "\n";

    std::cout << "After passing the array through the function findMax, "
                 "we get the result: " << std::endl;
    findMax(arr, arrSize);
    std::cout << "\n";

    std::cout << "After passing the array through the function findMin, "
                 "we get the result: " << std::endl;
    findMin(arr, arrSize);
    std::cout << "\n";

    std::cout << "After passing the array through the function findSum, "
                 "we get the result: " << std::endl;
    findSum(arr, arrSize);
    std::cout << "\n";

    std::cout << "After passing the array through the function findAvg, "
                 "we get the result: " << std::endl;
    findAvg(arr, arrSize);
    std::cout << "\n";

    std::cout << "After passing the array through the function sortArray, "
                 "the order is now: " << std::endl;
    sortArray(arr, arrSize);
    printArray(arr, arrSize);

    return 0;
}

void printArray(const int array[], int size) {
    for (int i{0}; i < size; i++) {
        std::cout << array[i] << " ";
    }
}

void reverseArray(int array[], int size) {
    for (int start = 0, end = size - 1; start < end; start++, end--) {
        int temp = array[start];
        array[start] = array[end];
        array[end] = temp;
    }
}

void findMax(const int array[], int size) {
    int max = array[0];

    for (int i{1}; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }

    std::cout << max;
}

void findMin(const int array[], int size) {
    int min = array[0];

    for (int i{1}; i < size; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }

    std::cout << min;
}

void findSum(const int array[], int size) {
    int sum{0};

    for (int i{0}; i < size; i++) {
        sum += array[i];
    }

    std::cout << sum;
}

void findAvg(const int array[], int size) {
    double avg;
    double sum{0};

    for (int i{0}; i < size; i++) {
        sum += array[i];
    }

    avg = sum / size;

    std::cout << avg;

}

void sortArray(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                // Swap array[j] and array[j + 1]
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}