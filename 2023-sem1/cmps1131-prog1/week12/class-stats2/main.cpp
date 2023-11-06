#include <iostream>

void classStatistics2(int);

int main() {
    classStatistics2(10);
    std::system("pause");
    return 0;
}

void classStatistics2(int grades) {
    int aCount{0}, bCount{0}, cCount{0},
    dCount{0}, fCount{0}, invalCount{0};

    for (; grades > 0; grades--) {
        std::cout << "Enter a letter grade: ";
        char studGrade;
        std::cin >> studGrade;

        switch (studGrade) {
            case 'A':
            case 'a':
                aCount++;
                break;
            case 'B':
            case 'b':
                bCount++;
                break;
            case 'C':
            case 'c':
                cCount++;
                break;
            case 'D':
            case 'd':
                dCount++;
                break;
            case 'F':
            case 'f':
                fCount++;
                break;
            default:
                invalCount++;
        }
    }
    std::cout << std::endl
    << "A - " << aCount << " students" << std::endl
    << "B - " << bCount << " students" << std::endl
    << "C - " << cCount << " students" << std::endl
    << "D - " << dCount << " students" << std::endl
    << "F - " << fCount << " students" << std::endl
    << "Invalid entry - " << invalCount << std::endl;
}
