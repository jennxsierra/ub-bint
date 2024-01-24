#include "invoice.h"
#include <iostream>

using namespace std;

int main()
{
    Invoice Invoice1;
    Invoice1.setItem("Milk");
    Invoice1.setPrice(6.00);
    Invoice1.setQuantity(5);
    Invoice1.display();
    cout << "Your invoice total is: $" << Invoice1.calculateTotal() << "\n";

    return 0;
}
