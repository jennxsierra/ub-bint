#include "circle.h"

Circle::Circle() = default;

Circle::Circle(double radius) {
    setRadius(radius);
}

void Circle::setRadius(double rad) {
    radius = (rad < 0.0  ? 0.0 : rad);
}

double Circle::getRadius() const {
    return radius;
}

double Circle::area() const {
    double area = 3.14159 * radius * radius;
    return area;
}

double Circle::circumference() const {
    double circumference = 2 * 3.14159 * radius;
    return circumference;
}
