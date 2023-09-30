//ATM Class Definition

#ifndef QUIZ2_ATM_H
#define QUIZ2_ATM_H
#include <iostream>
#include <string>

class ATM {

private:
    //Data Members
    std::string accountNumber;
    int interestRate{};
    float balance{};

public:
    //Constructor
    ATM(std::string newNumber, int newRate, float newBalance);

    //Function Members
    //Getter and Setter for accountNumber
    [[nodiscard]] std::string getAccountNumber() const;
    void setAccountNumber(std::string newNumber);

    //Getter and Setter for interestRate
    [[nodiscard]] int getInterestRate() const;
    void setInterestRate(int newRate);

    //Getter and Setter for balance
    [[nodiscard]] float getBalance() const;
    void setBalance(float newBalance);

    [[nodiscard]] float getEarnedInterest () const;
};


#endif //QUIZ2_ATM_H
