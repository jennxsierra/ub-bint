#include <iostream>
#include <cstring>

char sentence[] = "a fun sentence this is";
void tokenize(const char*);

int main() {

    std::cout << "Original sentence: " << sentence << std::endl;

    std::cout << "\nTokenized sentence: " << std::endl;
    tokenize(sentence);

    return 0;
}

void tokenize(const char* input) {
    char* token = strtok(const_cast<char*>(input), " ");

    while (token != nullptr) {
        std::cout << token << " ";

        char* ptr = token;
        while (*ptr != '\0') {
            if (strlen(token) < 4) {
                std::cout << "$";
            } else {
                std::cout << "#";
            }
            ++ptr;
        }

        token = strtok(nullptr, " ");
        std::cout << std::endl;
    }
}