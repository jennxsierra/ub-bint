#include <iostream>
#include <cstring>

char sentence[] = "This is a sentence with 7 tokens";
char *tokenPtr;

bool isConsonant(char);
void replaceConsonant(char *);

int main() {

    std::cout << "The string to be tokenized is: \n" << sentence << std::endl;

    std::cout << "\nThe tokens are: " << std::endl;

    tokenPtr = strtok(sentence, " ");

    while (tokenPtr != nullptr) {
        std::cout << tokenPtr << "  ";

        replaceConsonant(tokenPtr);
        std::cout << tokenPtr << std::endl;

        tokenPtr = strtok(nullptr, " ");
    }

    return 0;
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

void replaceConsonant(char *token) {
        while (*token != '\0') {
            if (isConsonant(*token) && isalpha(*token)) {
                *token = '$';
            }

            ++token;
        }
}