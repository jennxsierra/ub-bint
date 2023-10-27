#include <iostream>

void withdraw();

int main()
{
    withdraw();
    return 0;
}

void withdraw() {
    int acctNum;
    double begBal, amtWithdrawn, newBal;

    while (true) {
        std::cout << "Enter account number (or -1 to quit): ";
        std::cin >> acctNum;

        if (acctNum < 0) {
            break;
        }

        std::cout << "Enter beginning balance: ";
        std::cin >> begBal;

        std::cout << "Enter withdrawal amount: ";
        std::cin >> amtWithdrawn;

        newBal = begBal - amtWithdrawn;

        std::cout << "New Balance: " << newBal << "\n" << std::endl;
    }
}