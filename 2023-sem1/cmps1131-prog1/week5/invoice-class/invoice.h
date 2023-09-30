#ifndef INVOICE_H
#define INVOICE_H
#include <iostream>
#include <string>
using namespace std;

class Invoice
{
public:
    Invoice ();

    string getItem();
    double getPrice();
    int getQuantity();

    void setItem(string);
    void setPrice(double);
    void setQuantity(int);

    void display();
    double calculateTotal();

private:
    string item;
    double price;
    int quantity;
    double total;
};

#endif // INVOICE_H
