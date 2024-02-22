#include <iostream>

int a1[] = {42, 3, 9, 42, 42, 0, 42, 9, 42, 42, 17, 8, 2222, 4, 9, 0, 1};
int a2[] = {42, 2222, 9};
int len1 = sizeof(a1) / sizeof(a1[0]);
int len2 = sizeof(a2) / sizeof(a2[0]);

void printArray(int [], int);
void banish(int [], int, const int [], int);

int main() {

    std::cout << "Array 1: ";
    printArray(a1, len1);
    std::cout << "Array 2: ";
    printArray(a2, len2);

    std::cout << "\nBanishing array 2 from array 1...";
    banish(a1, len1, a2, len2);
    std::cout << "\nDone!" << std::endl;

    std::cout << "\nArray 1: ";
    printArray(a1, len1);

    return 0;
}

void printArray(int array[], int length) {
    for (int i = 0; i < length; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void banish(int arr1[], int length1, const int arr2[], int length2) {
    int shift = 0;
    for (int i = 0; i < length1; ++i) {
        bool found = false;
        for (int j = 0; j < length2; ++j) {
            if (arr1[i] == arr2[j]) {
                found = true;
                break;
            }
        }
        if (found) {
            ++shift;
        } else if (shift > 0) {
            arr1[i - shift] = arr1[i];
        }
    }
    for (int i = length1 - shift; i < length1; ++i) {
        arr1[i] = 0;
    }
}