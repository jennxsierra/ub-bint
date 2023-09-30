#include "invoice.h"
#include <iostream>
#include <string>
using namespace std;

Invoice::Invoice()
{

}

string Invoice::getItem()
{
    return item;
}

double Invoice::getPrice()
{
    return price;
}

int Invoice::getQuantity()
{
    return quantity;
}

void Invoice::setItem(string item1)
{
    item = item1;
}

void Invoice::setPrice(double price1)
{
    if (price1 < 0)
    {
        price = 0;
    }
    else
    {
        price = price1;
    }
}

void Invoice::setQuantity(int quantity1)
{
    if (quantity1 < 0)
    {
        quantity = 0;
    }
    else
    {
        quantity = quantity1;
    }
}

void Invoice::display()
{
    cout << "Invoice: ";
    cout << getItem() << ", $" << getPrice() << ", " << getQuantity() << "\n";
}

double Invoice::calculateTotal()
{
    total = price * quantity;
    return total;
}
