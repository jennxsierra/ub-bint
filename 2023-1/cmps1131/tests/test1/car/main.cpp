#include <iostream>
#include "Car.h"


int main () {
    Car carObj{25000};
    std::cout << "The price of the car is $" << carObj.getPrice() << std::endl;

    carObj.setPrice(20000);
    std::cout << "The new price of the car is $" << carObj.getPrice() << std::endl;

    std::cout << "The depreciation of the car is $" << carObj.getDepreciation() << std::endl;

    return 0;
}