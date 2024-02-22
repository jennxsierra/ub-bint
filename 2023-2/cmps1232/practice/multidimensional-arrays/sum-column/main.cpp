#include <iostream>

const int rows = 50;
const int columns = 3;
int arr[rows][columns] = {{1,2, 3},
                          {4, 5, 6},
                          {7, 8, 9}};

void printLastRow(int [rows][columns], int, int);
void sumArray(int [rows][columns], int, int);

int main() {
    std::cout << "The function sumArray adds the values in each column"
                 "and stores the sum in the last row of each column." << std::endl;

    std::cout << "\nThe last row currently contains these values:" << std::endl;
    printLastRow(arr, 49, columns);

    std::cout << "\n\nAfter calling the function sumArray, the last row now contains these values:" << std::endl;
    sumArray(arr, 49, columns);
    std::cout << std::endl;

    return 0;
}

void printLastRow(int array[rows][columns], int row, int cols) {
    for (int i = 0; i < cols; i++) {
        std::cout << array[row][i] << " ";
    }
}

void sumArray(int array[rows][columns], int row, int cols) {
    int sum;
    for (int i = 0; i < cols; i++) {
        sum = 0;
        for (int j = 0; j < row; j++) {
            sum += array[j][i];
        }
        array[row][i] = sum;
    }
    printLastRow(array, row, cols);
}
