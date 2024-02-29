#include <iostream>
#include <iomanip>

const int rows = 4;
const int cols = 4;
int matrix[rows][cols] = {{5,  10,  15,  20},
                          {25, 30,  35,  40},
                          {45, 50,  55,  60},
                          {65, 70,  75,  80}};

void printArray(int[][cols]);
void doubleValues(int[][cols]);

int main() {
    std::cout << "Original Matrix:" << std::endl;
    printArray(matrix);

    std::cout << "\nModified Matrix:" << std::endl;
    doubleValues(matrix);

    return 0;
}

void printArray(int array[][cols]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << std::setw(6) << array[i][j];
        }
        std::cout << std::endl;
    }
}

void doubleValues(int array[][cols]) {
    int temp[rows][cols] = {};

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            temp[i][j] = array[i][j] * 2;
        }
    }

    printArray(temp);
}