#include <iostream>

const int length = 5;
int arr1[length] = {1, 5, 6, 7, 8};
int arr2[length] = {5, 1, 2, 3, 7};

int process(const int[], const int[], int);

int main() {

    int result = process(arr1, arr2, length);
    std::cout << "Elements above 50: " << result << std::endl;

    return 0;
}

int process(const int a[], const int b[], int size) {
    const int rows = 3;
    int temp[rows][size];

    for (int i = 0; i < size; ++i) {
        temp [0][i] = a[i];
    }

    for (int i = 0; i < size; ++i) {
        temp [1][i] = b[i];
    }

    for (int i = 0; i < size; ++i) {
        temp [2][i] = a[i] + b[i];
    }

    int counter = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < size; ++j) {
            if (temp[i][j] > 50) {
                counter++;
            }
        }
    }

    return counter;
}