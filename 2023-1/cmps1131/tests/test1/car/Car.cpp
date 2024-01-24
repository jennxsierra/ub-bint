#include "Car.h"

Car::Car(float newPrice) {
    setPrice(newPrice);
}

float Car::getPrice() const {
    return price;
}
void Car::setPrice(float newPrice) {
    price = (newPrice < 0) ? 0 : newPrice;
}

float Car::getDepreciation() const {
    return price * 4;
}