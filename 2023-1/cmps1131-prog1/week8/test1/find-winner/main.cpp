#include <iostream>
#include <string>

std::string findWinner(int, int);
int ptsBZ;
int ptsCB;

int main() {
    std::cout << "Belize: How many points did they score? ";
    std::cin >> ptsBZ;

    std::cout << "Cuba: How many points did they score? ";
    std::cin >> ptsCB;

    std::cout << findWinner(ptsBZ, ptsCB);

    return 0;
}

std::string findWinner(int scoreBZ, int scoreCB) {
    if (scoreBZ > scoreCB) {
        return "Belize won!\n";
    } else if (scoreCB > scoreBZ) {
        return "Cuba won!\n";
    } else {
        return "It's a draw!\n";
    }
}