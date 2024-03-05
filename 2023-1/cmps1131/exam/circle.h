#ifndef CIRCLE_H
#define CIRCLE_H

class Circle
{
public:
    Circle();
    explicit Circle(double radius);
    void setRadius(double rad);
    [[nodiscard]] double getRadius() const;
    [[nodiscard]] double area() const;
    [[nodiscard]] double circumference() const;

private:
    double radius{0.0};
};

#endif // CIRCLE_H