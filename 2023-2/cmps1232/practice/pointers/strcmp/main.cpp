#include <iostream>

char str1[] = "Happy New Year";
char str2[] = "Happy New Year";
char str3[] = "Happy Holidays";

int my_strcmp(char[], char[]);
int my_strncmp(char[], char[], size_t);

int main() {

    std::cout << "str1: " << str1 << std::endl;
    std::cout << "str2: " << str2 << std::endl;
    std::cout << "str3: " << str3 << std::endl;

    int result = my_strcmp(str1, str2);
    std::cout << "\nmy_strcmp(str1, str2): " << result << std::endl;

    result = my_strcmp(str1, str3);
    std::cout << "my_strcmp(str1, str3): " << result << std::endl;

    result = my_strcmp(str3, str1);
    std::cout << "my_strcmp(str3, str1): " << result << std::endl;

    result = my_strncmp(str1, str3, 6);
    std::cout << "\nmy_strncmp(str1, str3, 6): " << result << std::endl;

    result = my_strncmp(str1, str3, 7);
    std::cout << "my_strncmp(str1, str3, 7): " << result << std::endl;

    result = my_strncmp(str3, str1, 7);
    std::cout << "my_strncmp(str3, str1, 7): " << result << std::endl;

    return 0;
}


int my_strcmp(char *s1, char *s2) {
    while(*s1 && *s2) {
        if(*s1 != *s2) {
            return (*s1 < *s2) ? -1 : 1;
        }
        ++s1;
        ++s2;
    }

    if (*s1 != *s2) {
        return (*s1 < *s2) ? -1 : 1;
    }

    return 0;
}

int my_strncmp(char *s1, char *s2, size_t num) {
    while(*s1 && *s2 && num) {
        if(*s1 != *s2) {
            return (*s1 < *s2) ? -1 : 1;
        }
        ++s1;
        ++s2;
        --num;
    }

    if (num && (*s1 || *s2) && *s1 != *s2) {
        return (*s1 < *s2) ? -1 : 1;
    }

    return 0;
}