#include <iostream>

char array[] = "Boston";

void printArray(char []);
int stringLen(const char []);

int main() {
    std::cout << "Array: ";
    printArray(array);

    int length = stringLen(array);
    std::cout << "Length: " << length << std::endl;

    return 0;
}

void printArray(char arr[]) {
    for (int i = 0; i < 6; i++) {
        std::cout << arr[i];
    }
    std::cout << std::endl;
}

int stringLen(const char arr[]) {
    int count = 0;

    while (arr[count] != '\0') {
        count++;
    }

    return count;
}
