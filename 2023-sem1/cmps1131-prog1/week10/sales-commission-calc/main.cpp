#include <iostream>

double calculateEarnings(double);
void calculateAndDisplayEarnings();

int main() {
    calculateAndDisplayEarnings();
    return 0;
}

double calculateEarnings(double sales) {
    const double baseSalary = 200.0;
    const double commissionRate = 0.09;
    return baseSalary + (sales * commissionRate);
}

void calculateAndDisplayEarnings() {
    double sales;

    std::cout << "Enter sales in dollars (-1 to end): ";
    std::cin >> sales;

    while (sales != -1) {
        double earnings = calculateEarnings(sales);
        std::cout << "Salary is: $" << earnings << std::endl;

        std::cout << "Enter sales in dollars (-1 to end): ";
        std::cin >> sales;
    }
}
