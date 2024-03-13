#include <iostream>

const int size = 5;
int array[] = {2, 3, 1, 45, 15};

void printArray(int [], int);
void selectionSort(int *, int);

int main() {
    std::cout << "The array contains the following values:" << std::endl;
    printArray(array, size);

    std::cout << "After using the Selection Sort function, "
                 "the order is now:" << std::endl;
    selectionSort(array, size);

    return 0;
}

void printArray(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void selectionSort(int *p, int len) {
    for (int i = 0; i < len - 1; i++) {
        int min = i;

        for (int j = i + 1; j < len; j++) {
            if (*(p + j) < *(p + min)) {
                min = j;
            }
        }

        if (min != i) {
            int temp = *(p + i);
            *(p + i) = *(p + min);
            *(p + min) = temp;
        }
    }

    printArray(p, len);
}