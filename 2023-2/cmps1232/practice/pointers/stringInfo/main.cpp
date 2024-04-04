#include <iostream>
#include <cstring>

char sentence[] = "this is fun";
char copy[] = "this is fun";

int stringInfo(const char*, char);
void stringInfo2(char*, char);
void stringInfo3(char*);

int main() {
    std::cout << "The sentence is: " << sentence << std::endl;

    int result = stringInfo(sentence, 's');
    std::cout << "\nstringInfo(sentence, 's') = " << result << " times." << std::endl;

    stringInfo2(sentence, 's');
    std::cout << "stringInfo2(sentence, 's') = " << sentence << std::endl;

    std::cout << "stringInfo3(sentence): \n";
    stringInfo3(copy);

    std::cin.get();
    return 0;
}

int stringInfo(const char* string, const char letter) {
    int count = 0;

    while (*string != '\0') {
        if (*string == letter) {
            count++;
        }
        string++;
    }

    return count;
}

void stringInfo2(char* string, const char letter) {
    while (*string != '\0') {
        if (*string == letter) {
            *string = '$';
        }

        string++;
    }
}

void stringInfo3(char* string) {
    char* token = std::strtok(string, " ");

    while (token != nullptr) {
        std::cout << "token: " << token << ",\t";

        std::size_t length = std::strlen(token);
        std::cout << "length: " << length << ",\t";

        char temp = *token;
        *token = *(token + length - 1);
        *(token + length - 1) = temp;

        std::cout << "swap: " << token << "\n\n";

        token = std::strtok(nullptr, " ");
    }
}