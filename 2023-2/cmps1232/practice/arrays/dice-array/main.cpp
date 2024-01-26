#include <iostream>
#include <ctime>

const int arraySize{6};
const int rolls{50};
int frequency[arraySize] {};

void rollDice(int [], int);
void printFrequencies(int [], int);

int main() {
    std::cout << "A dice is rolled " << rolls << " times:\n" << std::endl;

    // Roll the dice 50 times
    srand(time(0));
    rollDice(frequency, rolls);

    // Print the frequencies
    printFrequencies(frequency, arraySize);

    return 0;
}

void rollDice(int array[], int times) {
    for (int i{1}; i <= times; ++i) {
        int value = 1 + rand() % 6;
        ++array[value - 1];
    }
}

void printFrequencies(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << "Face " << (i + 1) << " was rolled " << array[i] << " times\n";
    }
}