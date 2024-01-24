#include <iostream>

double calculateGrossPay(int, double);
void calculateAndDisplayGrossPay();

int main() {
    calculateAndDisplayGrossPay();
    return 0;
}

double calculateGrossPay(int hoursWorked, double hourlyRate) {
    const int regularHours = 40;
    const double overtimeRate = 1.5;

    if (hoursWorked <= regularHours) {
        return hoursWorked * hourlyRate;
    } else {
        int regularPay = regularHours * hourlyRate;
        int overtimeHours = hoursWorked - regularHours;
        double overtimePay = overtimeHours * hourlyRate * overtimeRate;
        return regularPay + overtimePay;
    }
}

void calculateAndDisplayGrossPay() {
    int hoursWorked;
    double hourlyRate;

    std::cout << "Enter hours worked (-1 to end): ";
    std::cin >> hoursWorked;

    while (hoursWorked != -1) {
        std::cout << "Enter hourly rate of the employee ($00.00): ";
        std::cin >> hourlyRate;

        double grossPay = calculateGrossPay(hoursWorked, hourlyRate);
        std::cout << "Salary is $" << grossPay << std::endl;

        std::cout << "Enter hours worked (-1 to end): ";
        std::cin >> hoursWorked;
    }
}
