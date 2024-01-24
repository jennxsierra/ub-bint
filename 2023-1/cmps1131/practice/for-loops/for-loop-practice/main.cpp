#include <iostream>
#include <string>

std::string repeat(const std::string&, int);
void printSumofFive();
void printTesting();

int main() {
    std::string result = repeat("Hello",4);
    std::cout << result << "\n" << std::endl;

    printSumofFive();
    std::cout << std::endl;

    printTesting();
    std::cout << std::endl;

    return 0;
}

std::string repeat(const std::string& word, int count) {
    std::string repeatedWord;
    for (int i{0}; i < count - 1; i++) {
        repeatedWord += word + " ";
    }
    repeatedWord += word;
    return repeatedWord;
}
void printSumofFive() {
    int sum{0};
    for (int k{1}; k <= 5; k++) {
        sum += k;
        std::cout << sum << k << "\n";
    }
}

void printTesting() {
    int k{3};
    while (k > 0) {
        std::cout << "testing";
        k--;
    }
}