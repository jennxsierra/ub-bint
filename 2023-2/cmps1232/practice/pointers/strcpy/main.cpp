#include <iostream>
#include <cstring>

char array[] = "Happy Birthday To You";
char copy[25];
void printArray(char *);
void copyArray(char *, char *);

int main() {
    std::cout << "Initial Array: ";
    printArray(array);

    std::cout << "Copied Array: ";
    copyArray(array, copy);
    printArray(copy);

    return 0;
}

void printArray(char *arr) {
    for (int i = 0; i < strlen(arr); i++) {
        std::cout << *(arr + i);
    }
    std::cout << std::endl;
}

void copyArray(char *arr, char *arrCopy) {
    for (int i = 0; i < strlen(arr); i++) {
        *(arrCopy + i) = *(arr + i);
    }
}
