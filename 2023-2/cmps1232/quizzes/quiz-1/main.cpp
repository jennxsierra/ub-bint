#include <iostream>

int grade;
const int arrSize{5};
int gradebook[arrSize]{};


int main()
{
    for (int i{0}; i < 10; i++) {
        std::cout << "[" << i << "] " << "Please enter the student's grade: ";
        std::cin >> grade;

        if (grade >= 90 && grade <= 100) {
            ++gradebook[0];
        } else if (grade >= 80 && grade <= 89) {
            ++gradebook[1];
        } else if (grade >= 70 && grade <= 79) {
            ++gradebook[2];
        } else if (grade >= 60 && grade <= 69) {
            ++gradebook[3];
        } else if (grade >= 0 && grade <= 59) {
            ++gradebook[4];
        } else {
            std::cout << "Invalid grade.\n";
        }
    }

    std::cout << "\nResults:\n";
    std::cout << "The number of A - " << gradebook[0] << std::endl;
    std::cout << "The number of B - " << gradebook[1] << std::endl;
    std::cout << "The number of C - " << gradebook[2] << std::endl;
    std::cout << "The number of D - " << gradebook[3] << std::endl;
    std::cout << "The number of F - " << gradebook[4] << std::endl;

    return 0;
}
