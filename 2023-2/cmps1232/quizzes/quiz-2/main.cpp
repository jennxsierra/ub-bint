#include <iostream>

int numOccur(const char [], char, int);

const int arraySize{5};
int a[arraySize]{1, 2, 1, 5, 2};

void printArray (int [], int);
void eliminate_duplicates (int [], int);
bool isUnique(const int [], int, int);

int main() {
    std::cout << "Question #1: \n";
    const int arrSize = 6;
    char arr[arrSize] = "hello";
    char letter;

    std::cout << "Enter a letter to search for: ";
    std::cin >> letter;

    int result = numOccur(arr, letter, arrSize);
    std::cout << "Number of occurrences: " << result << "\n";
    std::cout << std::endl;

    std::cout << "Question #2: \n";

    std::cout << "The array currently contains these integers: \n";
    printArray(a, arraySize);
    std::cout << std::endl;

    std::cout << "After using eliminate_duplicates, the array now contains these integers: \n";
    eliminate_duplicates(a, arraySize);
    std::cout << std::endl;

    return 0;
}

int numOccur(const char array[], char letter1, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] == letter1) {
            count++;
        }
    }
    return count;
}

void printArray (int array[], int size) {
    for (int i{0}; i < size; i++) {
        std::cout << array[i] << " ";
    }
}

bool isUnique(const int array[], int size, int value) {
    for (int i{0}; i < size; i++) {
        if (array[i] == value) {
            return false;
        }
    }
    return true;
}

void eliminate_duplicates (int array[], int size) {
    int newArray[arraySize];
    int newArraySize = 0;

    for (int i = 0; i < size; i++) {
        if (isUnique(newArray, newArraySize, array[i])) {
            newArray[newArraySize] = array[i];
            newArraySize++;
        }
    }

    for (int i = 0; i < newArraySize; i++) {
        array[i] = newArray[i];
    }

    for (int i = newArraySize; i < size; i++) {
        array[i] = 0;
    }

    printArray(newArray, 3);
}

