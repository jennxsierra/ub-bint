#include <iostream>

int main() {

    //Prints odd numbers from 1 to 23, inclusive.
    int count = 1;
    while (count <= 23)
    {
        std::cout << count << " ";
        count += 2;
    }

    std::cout << "\n--------------------------------------------" << std::endl;

    //Totals 10 user input grades and provides average.
    int total = 0;
    int gradeCounter = 1;

    while (gradeCounter <= 10) {
        std::cout << "Enter grade: ";
        int grade;
        std::cin >> grade;

        total += grade;
        gradeCounter++;
    }

    int average = total / 10;

    std::cout << "The total of all grades is " << total << std::endl;
    std::cout << "The class average is " << average << std::endl;

    return 0;
}
