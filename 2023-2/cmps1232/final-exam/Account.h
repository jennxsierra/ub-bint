#ifndef BINT_ACCOUNT_H
#define BINT_ACCOUNT_H

#include <string>

class Account {
public:
    Account();
    Account(std::string, double);
    void setAccountNumber(std::string);
    std::string getAccountNumber();
    void setBalance(double);
    [[nodiscard]] double getBalance() const;

private:
    std::string accountNumber;
    double balance;
};

#endif //BINT_ACCOUNT_H