#include <iostream>

int a[] = {1, 4, 2, 4, 7, 1, 1, 9, 2, 3, 4, 1};
void printArray (int [], int);
bool isUnique(const int [], int, int);
int countDuplicates (int [], int);

int main() {
    std::cout << "The array currently contains these integers: \n";
    printArray(a, 12);
    std::cout << std::endl;

    std::cout << "After checking with countDuplicates, "
                 "the array contains these many duplicates: \n";
    int result = countDuplicates(a, 12);
    std::cout << result << std::endl;
    std::cout << std::endl;

    return 0;
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

int countDuplicates (int array[], int size) {
    int newArray[size];
    int newArraySize = 0;
    int count = 0;

    for (int i = 0; i < size; i++) {
        if (isUnique(newArray, newArraySize, array[i])) {
            newArray[newArraySize] = array[i];
            newArraySize++;
        } else {
            count++;
        }
    }

    return count;
}