#include <iostream>
#include <iomanip>
#include <fstream>
#include "Account.h"

int main() {
    std::string accountNum;
    double bal;
    char choice;

    std::fstream AccFile("..\\Accounts.dat", std::ios::in | std::ios::out | std::ios::binary);

    if (!AccFile) {
        std::cerr << "Error: File could not be opened." << std::endl;
        exit(1);
    }

    Account objAccount;

    while (true) {
        std::cout << "Enter account number: ";
        std::cin >> accountNum;

        std::cout << "Enter balance: ";
        std::cin >> bal;

        objAccount.setAccountNumber(accountNum);
        objAccount.setBalance(bal);

        std::cout << "\nAccount number: " << objAccount.getAccountNumber() << std::endl;
        std::cout << "Balance: " << std::fixed << std::setprecision(2) << objAccount.getBalance() << std::endl;

        AccFile.seekp((std::stoi(objAccount.getAccountNumber())-1) * sizeof(Account));
        AccFile.write(reinterpret_cast<char *>(&objAccount), sizeof(objAccount));

        std::cout << "\nDo you want to enter another account? (Y/N): ";
        std::cin >> choice;

        if (choice == 'N' || choice == 'n') {
            break;
        }

        std::cout << std::endl;
    }

    AccFile.close();

    std::cin.get();
}
