#ifndef CLASSES_REVIEW_POINT_H
#define CLASSES_REVIEW_POINT_H

class Point {
private:
    int xcoordinate;
    int ycoordinate;

public:
    // Constructors
    Point(); // Default constructor
    Point(int x, int y); // Parameterized constructor

    // Getter and setter functions
    int getXCoordinate() const;
    void setXCoordinate(int x);
    int getYCoordinate() const;
    void setYCoordinate(int y);

    // Member functions
    void moveRight(int distance);
    void moveUp(int distance);
    void display() const;
};

#endif //CLASSES_REVIEW_POINT_H
