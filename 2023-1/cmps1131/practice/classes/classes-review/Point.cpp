#include "Point.h"
#include <iostream>

// Default constructor
Point::Point() {
    xcoordinate = 0;
    ycoordinate = 0;
}

// Parameterized constructor
Point::Point(int x, int y) {
    xcoordinate = (x > 0) ? x : 0;
    ycoordinate = (y > 0) ? y : 0;
}

// Getter and setter functions for xcoordinate
int Point::getXCoordinate() const {
    return xcoordinate;
}

void Point::setXCoordinate(int x) {
    xcoordinate = (x > 0) ? x : 0;
}

// Getter and setter functions for ycoordinate
int Point::getYCoordinate() const {
    return ycoordinate;
}

void Point::setYCoordinate(int y) {
    ycoordinate = (y > 0) ? y : 0;
}

// Function to move the point right by a specified distance
void Point::moveRight(int distance) {
    xcoordinate += distance;
}

// Function to move the point up by a specified distance
void Point::moveUp(int distance) {
    ycoordinate += distance;
}

// Function to display the point in the format (x, y)
void Point::display() const {
    std::cout << "(" << xcoordinate << "," << ycoordinate << ")" << std::endl;
}