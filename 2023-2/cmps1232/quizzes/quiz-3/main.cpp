#include <iostream>

const int rows = 50;
const int cols = 50;
int temp[rows][cols] = {{1, 2},
                        {3, 4}};

void printLastCol(int [][cols], int, int);
void sumRows(int [][cols]);

const int array_size = 3;
int table[array_size][array_size] = {};

void printArray(int [][array_size], int, int);
int findSmallest(int [][array_size]);

int main() {
    std::cout << "Question 1:" << std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout << "The last column currently contains these values:" << std::endl;
    printLastCol(temp, 2, 49);

    std::cout << "\nAfter using sumRows, "
                 "the last column now contains these values: " << std::endl;
    sumRows(temp);
    printLastCol(temp, 2, 49);

    std::cout << "\n\nQuestion 2:" << std::endl;
    std::cout << "-------------------------" << std::endl;

    int num;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << "Please enter a number: ";
            std::cin >> num;
            table[i][j] = num;
        }
    }

    std::cout << "The array now contains these values: " << std::endl;
    printArray(table, array_size, array_size);

    std::cout << "\nThe smallest value in the array is ";
    int min = findSmallest(table);
    std::cout << min;

    return 0;
}

void printLastCol(int array[][cols], int row, int col) {
    for (int i = 0; i < row; ++i) {
        std::cout << array[i][col] << " ";
    }
}

void sumRows(int array[][cols]) {
    for (int i = 0; i < rows; ++i) {
        int sum = 0;
        for (int j = 0; j < cols; ++j) {
            sum += array[i][j];
        }
        array[i][cols - 1] = sum;
    }
}

void printArray(int array[][array_size], int row, int col) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int findSmallest(int array[][array_size]) {
    int smallest = array[0][0];
    for (int i = 0; i < array_size; ++i) {
        for (int j = 0; j < array_size; ++j) {
            if (array[i][j] < smallest) {
                smallest = array[i][j];
            }
        }
    }
    return smallest;
}