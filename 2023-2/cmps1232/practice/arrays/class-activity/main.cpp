#include <iostream>

const int arrSize {5};
int arr[arrSize] {8, 1, 6, 7, 1};

void printArray(const int array[], int size); //Prints the array
int findMax(const int [], int); //Finds the max value in the array
int findSum(const int [], int); //Returns the sum of the values in the array
int findFreq(const int [], int); //Returns the most frequent element in the array

int main() {
    std::cout << "The array contains the following numbers: " << std::endl;
    printArray(arr, arrSize);
    std::cout << "\n";

    std::cout << "After passing the array through the function findSum, "
                 "we get the result: " << std::endl;
    int result = findSum(arr, arrSize);
    std::cout << result << "\n";

    std::cout << "After passing the array through the function findMax, "
                 "we get the result: " << std::endl;
    int max = findMax(arr, arrSize);
    std::cout << max << "\n";

    std::cout << "After passing the array through the function findFreq, "
                 "we get the result: " << std::endl;
    int freq = findFreq(arr, arrSize);
    std::cout << freq << "\n";

    return 0;
}

void printArray(const int array[], int size) {
    for (int i{0}; i < size; i++) {
        std::cout << array[i] << " ";
    }
}

int findSum(const int array[], int size) {
    int sum{0};

    for (int i{0}; i < size; i++) {
        sum += array[i];
    }
    return sum;
}

int findMax(const int array[], int size) {
    int max = array[0];

    for (int i{1}; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

int findFreq(const int array[], int size) {
    int freq{0};
    int maxFreq{0};
    int maxFreqNum{0};

    for (int i{0}; i < size; i++) {

        for (int j{0}; j < size; j++) {
            if (array[i] == array[j]) {
                freq++;
            }
        }

        if (freq > maxFreq) {
            maxFreq = freq;
            maxFreqNum = array[i];
        }

        freq = 0;
    }
    return maxFreqNum;
}
