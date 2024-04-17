#include <iostream>
#include "Account.h"

Account::Account() {
}

Account::Account(std::string accountNum, double bal) {
    setAccountNumber(accountNum);
    setBalance(bal);
}

void Account::setAccountNumber(std::string accountNum) {
    accountNumber = accountNum;
}

std::string Account::getAccountNumber() {
    return accountNumber;
}

void Account::setBalance(double bal) {
    if (bal < 0) {
        std::cout << "Error: Balance cannot be negative." << std::endl;
    } else {
        balance = bal;
    }
}

double Account::getBalance() const {
    return balance;
}