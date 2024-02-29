#include <iostream>

const int rows = 5;
const int cols = 5;
int matrix[rows][cols] = {{23,  45,  12,  67,  89},
                          {34,  56,  78,  90,  10},
                          {11,  22,  33,  44,  55},
                          {66,  77,  88,  99,  100},
                          {9,   8,   7,   6,   5}};

void printArray(int[][cols]);
double findAverage(int[][cols]);

int main() {
    std::cout << "\tMatrix:" << std::endl;
    std::cout << "\t----------------------------------" << std::endl;
    printArray(matrix);

    double result = findAverage(matrix);
    std::cout<< "\nAverage: " << result;

    return 0;
}

void printArray(int array[][cols]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout<< "\t" << array[i][j];
        }
        std::cout << std::endl;
    }
}

double findAverage(int array[][cols]) {
    double sum = 0;
    double avg;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            sum += array[i][j];
        }
    }

    avg = sum / (rows * cols);
    return avg;
}
