//ATM Class Driver Program

#include <iostream>
#include "ATM.h"

int main() {
    ATM atmObj{"0123456789", 5, 1000.0};

    std::cout << "ATM:\n-----------------------------" << std::endl;
    std::cout << "Account Number: " << atmObj.getAccountNumber() << std::endl;
    std::cout << "Interest Rate: " << atmObj.getInterestRate() << "%" << std::endl;
    std::cout << "Balance: $" << atmObj.getBalance() << std::endl;

    atmObj.setBalance(10000.0);

    std::cout << "New Balance: $" << atmObj.getBalance() << std::endl;
    std::cout << "The Earned Interest is $" << atmObj.getEarnedInterest() << std::endl;

    return 0;
}
