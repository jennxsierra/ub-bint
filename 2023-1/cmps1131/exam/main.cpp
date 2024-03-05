#include <iostream>
#include "circle.h"

int main()
{
    Circle testCircle{10};
    std::cout << "The radius of the circle is " << testCircle.getRadius() << std::endl;

    testCircle.setRadius(20);
    std::cout << "The new radius of the circle is " << testCircle.getRadius() << std::endl;

    std::cout << "The area of the circle is " << testCircle.area() << std::endl;

    std::cout << "The circumference of the circle is " << testCircle.circumference() << std::endl;

    return 0;
}
