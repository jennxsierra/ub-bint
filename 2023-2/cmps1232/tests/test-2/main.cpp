#include <iostream>
#include <cstring>

// Question 1 declarations
char sentence[] = "a fun sentence this is";
char *tokenPtr;

bool isVowel(char);
void replaceVowel(char *);

// Question 2 declarations
char string1[25];
char string2[] = "Happy New Year";

char* strcpy(char*, const char*);

//Question 3 declarations
char sentence2[45] = "fluent in programming is tough but worth it!";

bool search(char*, char);

int main() {
    std::cout << "\tQuestion 1:\n";
    std::cout << "-----------------------------" << std::endl;
    std::cout << "The string to be tokenized is: \n" << sentence << std::endl;

    std::cout << "\nThe tokens are: " << std::endl;

    tokenPtr = strtok(sentence, " ");

    while (tokenPtr != nullptr) {
        std::cout << tokenPtr << " ";

        replaceVowel(tokenPtr);
        std::cout << tokenPtr << std::endl;

        tokenPtr = strtok(nullptr, " ");
    }

    std::cout << "\n\tQuestion 2:\n";
    std::cout << "----------------------------" << std::endl;
    std::cout << "String 1: " << string1 << std::endl;
    std::cout << "String 2: " << string2 << std::endl;

    std::cout << "\nAfter strcpy(string1, string2):\n";
    std::cout << "String 1: " << strcpy(string1, string2) << std::endl;
    std::cout << "String 2: " << string2 << std::endl;

    std::cout << "\n\tQuestion 3:\n";
    std::cout << "----------------------------" << std::endl;
    std::cout << "String: " << sentence2 << std::endl;

    bool result = search(sentence2, 's');
    std::cout << "search(sentence, 's'): " << result << std::endl;

    return 0;
}

// Question 1 functions
bool isVowel(const char letter) {
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
            return true;
        default:
            return false;
    }
}

void replaceVowel(char *token) {
    while (*token != '\0') {
        if (isVowel(*token)) {
            *token = '$';
        }

        ++token;
    }
}

// Question 2 function
char* strcpy(char* s1, const char* s2) {
    int counter = 0;

    while (*(s2 + counter) != '\0') {
        *(s1 + counter) = *(s2 + counter);
        ++counter;
    }

    *(s1 + counter) = '\0';

    return s1;
}

// Question 3 function
bool search(char* inputArray, char c) {
    while (*inputArray != '\0') {
        if(*inputArray == c) {
            return true;
        }
        ++inputArray;
    }

    return false;
}
