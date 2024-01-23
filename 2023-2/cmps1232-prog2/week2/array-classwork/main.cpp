#include <iostream>

int main() {
    int array1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int array2[10];

    //Copy numbers from array1 in reverse
    for (int i = 0; i < 10; ++i) {
        array2[i] = array1[9 - i];
    }

    //Print array2 to verify the result
    for (int i = 0; i < 10; ++i) {
        std::cout << array2[i] << " ";
    }

    return 0;
}