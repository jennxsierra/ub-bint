#include <iostream>

double calculateMPG(int, double);
void calculateTotalMPG();

int main() {
    calculateTotalMPG();
    return 0;
}

double calculateMPG(int miles, double gallons) {
    return miles / gallons;
}

void calculateTotalMPG() {
    int miles, totalMiles = 0;
    double gallons, totalGallons = 0, mpg, totalMPG = 0;

    std::cout << "Enter miles driven (-1 to quit): ";
    std::cin >> miles;

    while (miles != -1) {
        std::cout << "Enter gallons used: ";
        std::cin >> gallons;

        mpg = calculateMPG(miles, gallons);
        totalMiles += miles;
        totalGallons += gallons;
        totalMPG =totalMiles / totalGallons;

        std::cout << "MPG this trip: " << mpg << std::endl;
        std::cout << "Total MPG: " << totalMPG << std::endl;

        std::cout << "Enter miles driven (-1 to quit): ";
        std::cin >> miles;
    }
}

