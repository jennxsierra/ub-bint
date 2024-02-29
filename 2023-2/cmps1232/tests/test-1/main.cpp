#include <iostream>

// Constants
const int rows = 3;
const int cols = 3;
const int size = 5;

// Arrays
int array[rows][cols] = {{1, 2, 3},
                         {4, 5, 6},
                         {7, 8, 9}};
char a[size] = "name";
char b[size];

// Helper Functions
void printArray(int[][cols]);
void printString(char[], int);

// Question 1
void print(int[][cols]);

// Question 2
int findMaximum(int[][cols]);

// Question 3
void strcpyReverse(char[], const char[], int);

int main() {
    std::cout << "Question 1: " << std::endl;
    std::cout << "-------------------------" << std::endl;

    std::cout << "Array: " << std::endl;
    printArray(array);

    std::cout << "\nMain Diagonal: ";
    print(array);

    std::cout << "\n\nQuestion 2: " << std::endl;
    std::cout << "-------------------------" << std::endl;

    std::cout << "Array: " << std::endl;
    printArray(array);

    std::cout << "\nThe row with the maximum sum is: ";
    int maxRow = findMaximum(array);
    std::cout << maxRow << std::endl;

    std::cout << "\nQuestion 3: " << std::endl;
    std::cout << "-------------------------" << std::endl;

    std::cout << "The original string is: ";
    printString(a, size);

    std::cout << "\nThe reverse of the string is: ";
    strcpyReverse(b,a,size);
    std::cout << std::endl;

    return 0;
}

void printArray(int arr[][cols]) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            std::cout << "\t" << arr[i][j];
        }
        std::cout << std::endl;
    }
}

void printString(char arr[], int len) {
    for(int i = 0; i < len; i++) {
        std::cout << arr[i];
    }
}

void print(int arr[][cols]) {
    for(int i = 0; i < rows; i++) {
        std::cout << arr[i][rows - 1 - i] << " ";
    }
}

int findMaximum(int arr[][cols]) {
    int maxSum = 0;
    int maxRow = 0;

    for(int i = 0; i < rows; i++) {
        int sum = 0;

        for(int j = 0; j < cols; j++) {
            sum += arr[i][j];
        }

        if(sum > maxSum) {
            maxSum = sum;
            maxRow = i;
        }
    }

    return maxRow;
}

void strcpyReverse(char arr1[], const char arr2[], int len) {
    for(int i = 0; i < len; i++) {
        arr1[i] = arr2[len - 1 - i];
    }

    printString(arr1, len);
}
