#include <iostream>
#include "Point.h"

int main() {
    // Create a point object using the default constructor
    Point pointA;

    // Call the set functions to set the x-coordinate and y-coordinate for PointA
    pointA.setXCoordinate(5);
    pointA.setYCoordinate(6);

    // Call the display function to display PointA
    pointA.display();

    // Call the function to move right with a value
    pointA.moveRight(2);

    // Call the function to move up with a value
    pointA.moveUp(3);

    // Call the display function again to display the updated PointA
    pointA.display();

    return 0;
}
