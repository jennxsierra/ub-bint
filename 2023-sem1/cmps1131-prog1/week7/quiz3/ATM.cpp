//Implementation of ATM Class

#include "ATM.h"
#include <iostream>
#include <string>

ATM::ATM(std::string newNumber, int newRate, float newBalance) {
    setAccountNumber(newNumber);
    setInterestRate(newRate);
    setBalance (newBalance);
}

//Getter and Setter Fxn for accountNumber
std::string ATM::getAccountNumber() const {
    return accountNumber;
}
void ATM::setAccountNumber(std::string newNumber) {
    accountNumber = newNumber;
}

//Getter and Setter Fxn for interestRate
int ATM::getInterestRate() const {
    return interestRate;
}
void ATM::setInterestRate(int newRate) {
    interestRate = (newRate < 0) ? 0 : newRate;
}

//Getter and Setter Fxn for balance
float ATM::getBalance() const {
    return balance;
}
void ATM::setBalance(float newBalance) {
    balance = (newBalance < 0) ? 0 : newBalance;
}

//Fxn that calculates interest earned
float ATM::getEarnedInterest() const {
    return (interestRate * balance)/100;
}