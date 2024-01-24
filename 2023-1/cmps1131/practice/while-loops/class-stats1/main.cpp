#include <iostream>

void classStatistics1();

int main() {
    classStatistics1();
    return 0;
}

void classStatistics1() {
    char grade;
    while (true) {
        std::cout << "Enter a letter grade (Enter X to End): ";
        std::cin >> grade;

        if (grade == 'X' || grade == 'x') {
            break;
        }

        switch (grade) {
            case 'P':
            case 'p':
                std::cout << "Well done! You have passed the course.\n" << std::endl;
                break;
            case 'F':
            case 'f':
                std::cout << "You have failed the course.\n" << std::endl;
                break;
            default:
                std::cout << "This is not a valid grade.\n" << std::endl;
        }
    }
}
