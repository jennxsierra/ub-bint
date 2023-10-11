#ifndef TEST1_CAR_H
#define TEST1_CAR_H
#include <iostream>

class Car
{
public:
    Car(float newPrice);

    [[nodiscard]] float getPrice() const;
    void setPrice(float newPrice);

    [[nodiscard]] float getDepreciation() const;

private:
    float price;
};


#endif //TEST1_CAR_H
