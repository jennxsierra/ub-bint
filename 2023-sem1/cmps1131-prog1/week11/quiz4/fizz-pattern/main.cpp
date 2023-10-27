#include <iostream>

void fizzPattern(int);

int main()
{
    fizzPattern(4);
    return 0;
}


void fizzPattern(int repetitions) {
    int i{1};

    while (i <= repetitions) {
        if (i % 2 == 0) {
            std::cout << "###" << std::endl;
        } else {
            std::cout << "@@@" << std::endl;
        }
        i++;
    }
}