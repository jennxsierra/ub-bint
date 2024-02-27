#include <iostream>

const int length = 6;
int arr[length] = {1, 8, 1, 5, 6, 7};

void findTally(const int [], int);

int main() {
    std::cout << "Tally of the array elements: " << std::endl;
    findTally(arr, length);

    return 0;
}

void findTally(const int a[], int size) {
    int tally[2][size]; // 2D array to store unique elements and their frequency
    int uniqueCount = 0; // Count of unique elements

    for (int i = 0; i < size; i++) {
        bool found = false;
        for (int j = 0; j < uniqueCount; j++) {
            if (a[i] == tally[0][j]) {
                tally[1][j]++; // Increment frequency
                found = true;
                break;
            }
        }
        if (!found) {
            tally[0][uniqueCount] = a[i]; // Add unique element
            tally[1][uniqueCount] = 1; // Initialize frequency
            uniqueCount++;
        }
    }

    // Print the array
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < uniqueCount; ++j) {
            std::cout << tally[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

