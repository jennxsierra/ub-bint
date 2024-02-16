#include <iostream>

const int rows = 3;
const int cols = 3;
int arr[rows][cols] = {{1, 2, 3}, {5, 6, 7}, {9, 10, 11}};
void printArray(int [][cols], int, int);
int findSum(int [][cols], int, int );
int findProduct(int [][cols], int, int);
void printOddNumbers(int [][cols], int, int);
void printDiagonal(int [][cols], int, int);
int findSumDiagonal(int [][cols], int, int);

int main() {
    std::cout << "The array is: ";
    printArray(arr, rows, cols);

    std::cout << "\nSum of the last row is: ";
    int result = findSum(arr, rows, cols);
    std::cout << result;

    std::cout << "\nProduct of the last column is: ";
    result = findProduct(arr, rows, cols);
    std::cout << result;

    printOddNumbers(arr, rows, cols);

    printDiagonal(arr, rows, cols);
    std::cout << "\nSum of the diagonal elements is: ";
    result = findSumDiagonal(arr, rows, cols);
    std::cout << result;

    return 0;
}

// Function to print the array
void printArray(int array[][cols], int row, int col) {
    for (int i = 0; i < row; i++) {
        std::cout << std::endl;
        for (int j = 0; j < col; j++) {
            std::cout << array[i][j] << " ";
        }
    }
}

// Function to find the sum of the last row
int findSum(int array[][cols], int row, int col) {
    int sum = 0;
    for (int i = 0; i < col; i++) {
        sum += array[row - 1][i];
    }
    return sum;
}

// Function to find the product of the last column
int findProduct(int array[][cols], int row, int col) {
    int product = 1;
    for (int i = 0; i < row; i++) {
        product *= array[i][col - 1];
    }
    return product;
}

// Function to print the odd numbers in the array
void printOddNumbers(int array[][cols], int row, int col) {
    std::cout << "\nOdd numbers in the array are: ";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (array[i][j] % 2 != 0) {
                std::cout << array[i][j] << " ";
            }
        }
    }
}

// Function to print the diagonal elements
void printDiagonal(int array[][cols], int row, int col) {
    std::cout << "\nDiagonal elements are: ";
    for (int i = row - 1; i >= 0; i--) {
        for (int j = 0; j < col; j++) {
            if (i + j == row - 1) {
                std::cout << array[i][j] << " ";
            }
        }
    }
}

// Function to find the sum of the diagonal elements
int findSumDiagonal(int array[][cols], int row, int col) {
    int sum = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (i + j == row - 1) {
                sum += array[i][j];
            }
        }
    }
    return sum;
}
