#include <iostream>

char str1[20] = "Happy ";
char str2[] = "New Year ";
char str3[40] = "";

void my_strcat(char *, const char *);
void my_strncat(char *, const char *, size_t);

int main() {
    std::cout << "str1 = " << str1 << std::endl;
    std::cout << "str2 = " << str2 << std::endl;

    std::cout << "\nAfter strcat(str1, str2): " << std::endl;
    my_strcat(str1, str2);
    std::cout << "str1 = " << str1 << std::endl;
    std::cout << "str2 = " << str2 << std::endl;

    std::cout << "\nAfter strncat(str3, str1, 6): " << std::endl;
    my_strncat(str3, str1, 6);
    std::cout << "str1 = " << str1 << std::endl;
    std::cout << "str3 = " << str3 << std::endl;

    std::cout << "\nAfter strcat(str3, str1): " << std::endl;
    my_strcat(str3, str1);
    std::cout << "str1 = " << str1 << std::endl;
    std::cout << "str3 = " << str3 << std::endl;

    return 0;
}

void my_strcat(char *s1, const char *s2) {
    while(*s1) {
        ++s1;
    }

    while(*s2) {
        *s1 = *s2;
        ++s1;
        ++s2;
    }

    *s1 = '\0';
}

void my_strncat(char *s1, const char *s2, size_t num) {
    while(*s1) {
        ++s1;
    }

    while(*s2 && num--) {
        *s1 = *s2;
        ++s1;
        ++s2;
    }

    *s1 = '\0';
}