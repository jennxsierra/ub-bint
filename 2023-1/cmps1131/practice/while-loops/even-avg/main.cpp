#include <iostream>

int evenAverage();

int main() {
    int avg = evenAverage();
    std::cout << "Average of even numbers entered: " << avg << std::endl;
    return 0;
}

int evenAverage() {
    int sum{0}, count{0}, num;

    while (true) {
        std::cout << "Enter an Integer (0 to end): ";
        std::cin >> num;

        if (num == 0) {
            break;
        }

        if (num % 2 == 0) {
            sum += num;
            count++;
        }
    }

    if (count != 0) {
        return sum / count;
    } else {
        return 0;
    }
}
