#include <iostream>

const int arrSize{5};
int arr[arrSize]{1, 2, 3, 4, 5};
int num;

bool tfNum(int, const int [], int);

int main() {
    std::cout << "Please enter a number: ";
    std::cin >> num;

    bool result = tfNum(num, arr, arrSize);

    std::cout << "Is the number in the array? " << std::boolalpha << result;

    return 0;
}

bool tfNum(int number, const int array[], int size) {
    for (int i{0}; i < size; ++i) {
        if (number == array[i]) {
            return true;
        }
    }
    return false;
}