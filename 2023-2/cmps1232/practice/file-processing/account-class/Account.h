#ifndef ACCOUNT_CLASS_ACCOUNT_H
#define ACCOUNT_CLASS_ACCOUNT_H

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


#endif //ACCOUNT_CLASS_ACCOUNT_H
