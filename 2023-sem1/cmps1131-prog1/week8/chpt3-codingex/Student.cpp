#include "Student.h"
using string = std::string;

// Constructor implementation
Student::Student(string fName, string lName, int grade1, int grade2, int grade3) {
    setFirstName(fName);
    setLastName(lName);
    setExamGrade1(grade1);
    setExamGrade2(grade2);
    setExamGrade3(grade3);
}

// Getter and Setter implementations
string Student::getFirstName() const {
    return firstName;
}

void Student::setFirstName(string fName) {
    firstName = fName;
}

string Student::getLastName() const {
    return lastName;
}

void Student::setLastName(string lName) {
    lastName = lName;
}

int Student::getExamGrade1() const {
    return examGrade1;
}

void Student::setExamGrade1(int grade1) {
    examGrade1 = grade1;
}

int Student::getExamGrade2() const {
    return examGrade2;
}

void Student::setExamGrade2(int grade2) {
    examGrade2 = grade2;
}

int Student::getExamGrade3() const {
    return examGrade3;
}

void Student::setExamGrade3(int grade3) {
    examGrade3 = grade3;
}

// Function to calculate average exam grade
double Student::getAverage() const {
    return (examGrade1 + examGrade2 + examGrade3) / 3.0;
}
