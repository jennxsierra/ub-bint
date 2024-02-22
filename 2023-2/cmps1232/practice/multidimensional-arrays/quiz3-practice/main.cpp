#include <iostream>

const int rows = 3;
const int cols = 3;
int array[rows][cols] = {{1, 2, 3},
                         {4, 5, 6},
                         {7, 8, 9}};

void printArray(int [rows][cols], int, int);
int findSum(int [rows][cols], int, int);
float findAverage(int [rows][cols], int);
float findMedian(int [rows][cols], int, int);
int findMaxInDiagonal(int [rows][cols], int, int);

int main() {
    std::cout << "The array currently contains these elements: " << std::endl;
    printArray(array, rows, cols);

    std::cout << "\nThe sum of all elements in the array is ";
    int sum = findSum(array, rows, cols);
    std::cout << sum << std::endl;

    std::cout << "The average of all elements in the array is ";
    float avg = findAverage(array, 9);
    std::cout << avg << std::endl;

    std::cout << "The median of the array is ";
    float median = findMedian(array, rows, cols);
    std::cout << median << std::endl;

    std::cout << "The maximum value in the main diagonal of the array is ";
    int max = findMaxInDiagonal(array, rows, cols);
    std::cout << max << std::endl;

    return 0;
}

void printArray(int arr[rows][cols], int row, int col) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int findSum(int arr[rows][cols], int row, int col) {
    int sum = 0;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            sum += arr[i][j];
        }
    }
    return sum;
}

float findAverage(int arr[rows][cols], int size) {
    int sum = findSum(array, rows, cols);
    float avg = sum / size;

    return avg;
}

float findMedian(int arr[rows][cols], int row, int col){
    int size = row * col;
    int temp[size];
    int k = 0;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            temp[k] = arr[i][j];
            k++;
        }
    }
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (temp[i] > temp[j]) {
                int tempVar = temp[i];
                temp[i] = temp[j];
                temp[j] = tempVar;
            }
        }
    }
    if (size % 2 == 0) {
        return (temp[(size / 2) - 1] + temp[size / 2]) / 2.0;
    } else {
        return temp[size / 2];
    }
}

int findMaxInDiagonal(int arr[rows][cols], int row, int col) {
    int max = arr[0][0];
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (i == j) {
                if (arr[i][j] > max) {
                    max = arr[i][j];
                }
            }
        }
    }
    return max;
}
