#include <iostream>

char s1[] = "fun";
char s2[] = "funny";
char s3[] = "a fun sentence this is";

int mystrlen(const char*);
void wordReplace(char* );

bool checkVowel(char);
void vowelReplace(char*);

int main() {
    std::cout << "s1 = " << s1 << std::endl;
    std::cout << "s2 = " << s2 << std::endl;

    wordReplace(s1);
    std::cout << "\nwordReplace(s1) = " << s1 << std::endl;

    wordReplace(s2);
    std::cout << "wordReplace(s2) = " << s2 << std::endl;

    std::cout << "\ns3 = " << s3 << std::endl;
    vowelReplace(s3);
    std::cout << "vowelReplace(s3) = " << s3 << std::endl;

    return 0;
}

int mystrlen(const char* string) {
    int count{0};

    while (*(string + count) != '\0') {
        ++count;
    }

    return count;
}

void wordReplace(char* string) {
    int length = mystrlen(string);

    if (length < 4) {
        for (int i = 0; i < length; i++) {
            *(string + i) = '$';
        }
    } else {
        for (int i = 0; i < length; i++) {
            *(string + i) = '#';
        }
    }
}

bool checkVowel(const char letter) {
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

void vowelReplace(char* string) {
    while (*string != '\0') {
        if (checkVowel(*string)) {
            *string = '$';
        }

        ++string;
    }
}





