#include <iostream>
#include <iomanip>
#include <fstream>
#include "Account.h"

int main() {
    std::ofstream outAcc("..\\AccountsData.dat", std::ios::out | std::ios::binary);

    if (!outAcc) {
        std::cerr << "Error: File could not be opened." << std::endl;
        exit(1);
    }

    Account account{};

    while (true) {
        std::cout << "Enter account number (N to stop): ";
        std::string accountNum;
        std::getline(std::cin >> std::ws, accountNum);

        if (accountNum == "N" || accountNum == "n") {
            break;
        }

        std::cout << "Enter balance: ";
        double bal;
        std::cin >> bal;

        account.setAccountNumber(accountNum);
        account.setBalance(bal);

        outAcc.seekp((std::stoi(account.getAccountNumber()) - 1) * sizeof(Account));
        outAcc.write(reinterpret_cast<char *>(&account), sizeof(account));

        std::cout << std::endl;
    }

    outAcc.close();

    // reading from the file
    std::ifstream inAcc("..\\AccountsData.dat", std::ios::in);

    if (!inAcc) {
        std::cerr << "Error: File could not be opened." << std::endl;
        exit(1);
    }

    Account readAccount{};

    std::cout << "Enter account number to access data: ";
    int accNum;
    std::cin >> accNum;

    inAcc.seekg((accNum - 1) * sizeof(Account));
    inAcc.read(reinterpret_cast<char *>(&readAccount), sizeof(Account));

    inAcc.close();

    // writing to the file
    std::ofstream txtAcc("..\\AccountsPrinted.txt", std::ios::out);

    txtAcc << "Account number: " << readAccount.getAccountNumber() << '\n'
    << "Balance: " << std::fixed << std::setprecision(2) << readAccount.getBalance() << std::endl;

    txtAcc.close();

    std::cout << "Data written to AccountsPrinted.txt" << std::endl;

    system("pause");
}
