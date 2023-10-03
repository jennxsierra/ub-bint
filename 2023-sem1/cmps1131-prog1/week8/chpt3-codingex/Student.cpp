#include "Student.h"
using string = std::string;

// Constructor implementation
Student::Student(string fName, string lName, int grade1, int grade2, int grade3) {
    firstName = fName;
    lastName = lName;
    examGrade1 = grade1;
    examGrade2 = grade2;
    examGrade3 = grade3;
}

// Getter and Setter implementations
string Student::getFirstName() {
    return firstName;
}

void Student::setFirstName(string fName) {
    firstName = fName;
}

string Student::getLastName() {
    return lastName;
}

void Student::setLastName(string lName) {
    lastName = lName;
}

int Student::getExamGrade1() {
    return examGrade1;
}

void Student::setExamGrade1(int grade) {
    examGrade1 = grade;
}

int Student::getExamGrade2() {
    return examGrade2;
}

void Student::setExamGrade2(int grade) {
    examGrade2 = grade;
}

int Student::getExamGrade3() {
    return examGrade3;
}

void Student::setExamGrade3(int grade) {
    examGrade3 = grade;
}

// Function to calculate average exam grade
double Student::getAverage() {
    return (examGrade1 + examGrade2 + examGrade3) / 3.0;
}
