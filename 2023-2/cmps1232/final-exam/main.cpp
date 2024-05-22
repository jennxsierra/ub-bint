#include <iostream>
#include <cstring>
#include <fstream>
#include "Account.h"

// Question 2 declarations
const int size = 5;
int array[size] = {1, 2, 3, 4, 5};
void printArray(int[], int);
void rotateRight(int[], int);

// Question 3 declarations
char sentence[] = "a fun sentence this is";
void tokenize(const char*);

int main() {
    std::cout << "\tQuestion 1:\n";
    std::cout << "-----------------------------" << std::endl;
    std::fstream file("..\\accFile.txt", std::ios::out | std::ios::binary);

    if(!file) {
        std::cerr << "File could not be opened." << std::endl;
        exit(1);
    }

    Account account{};
    char choice;

    while(true) {
        std::cout << "Enter account number (N to stop): ";
        std::cin >> choice;

        if(choice == 'n' || choice == 'N') {
            break;
        }

        std::cout << "\nEnter city name: ";
        std::string accountNum;
        std::getline(std::cin >> std::ws, accountNum);

        std::cout << "Enter balance: ";
        double bal;
        std::cin >> bal;

        account.setAccountNumber(accountNum);
        account.setBalance(bal);

        file.write(reinterpret_cast<const char*>(&account), sizeof(Account));

        std::cout << std::endl;
    }

    file.close();

    std::cout << "\n\tQuestion 2:\n";
    std::cout << "-----------------------------" << std::endl;
    std::cout << "Original array: ";
    printArray(array, size);

    rotateRight(array, size);
    std::cout << "Array after using rotateRight: ";
    printArray(array, size);

    std::cout << "\n\tQuestion 3:\n";
    std::cout << "-----------------------------" << std::endl;
    std::cout << "Original sentence: " << sentence << std::endl;

    std::cout << "\nTokenized sentence: " << std::endl;
    tokenize(sentence);

    return 0;
}

void printArray(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void rotateRight(int arr[], int len) {
    int i, last;

    last = arr[len - 1];

    for (i = len - 1; i > 0; i--) {
        arr[i] = arr[i - 1];
    }

    arr[0] = last;
}

bool isConsonant(const char letter) {
    switch (letter) {
        case 'a':
        case 'A':
        case 'e':
        case 'E':
        case 'i':
        case 'I':
        case 'o':
        case 'O':
        case 'u':
        case 'U':
            return false;
        default:
            return true;
    }
}

void tokenize(const char* input) {
    char* token = strtok(const_cast<char*>(input), " ");

    while (token != nullptr) {
        std::cout << token << " ";

        char* ptr = token;
        while (*ptr != '\0') {
            if (isConsonant(*ptr)) {
                *ptr = '$';
            }
            ++ptr;
        }

        std::cout << token;

        token = strtok(nullptr, " ");
        std::cout << std::endl;
    }
}