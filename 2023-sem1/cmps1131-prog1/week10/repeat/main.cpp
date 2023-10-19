#include <iostream>
#include <string>

std::string repeat(const std::string&, int);

int main() {
    std::string result = repeat("Hello",4);
    std::cout << result;

    return 0;
}

std::string repeat(const std::string& word, int count) {
    std::string repeatedWord;
    int i = 0;
    while (i < count - 1) {
        repeatedWord += word + " ";
        i++;
    }
    repeatedWord += word;
    return repeatedWord;
}
