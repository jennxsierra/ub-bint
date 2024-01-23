#include <iostream>
#include "Student.h"

int main() {
    // Creating a Student object with initial values
    Student student("Jane", "Doe", 85, 90, 92);

    // Outputting the initial name and average grade
    std::cout << "Initial Name: " << student.getFirstName() << " " << student.getLastName() << std::endl;
    std::cout << "Initial Average Grade: " << student.getAverage() << std::endl;

    // Modifying student information using setter functions
    student.setFirstName("Jennessa");
    student.setLastName("Sierra");
    student.setExamGrade1(92);
    student.setExamGrade2(88);
    student.setExamGrade3(91);

    // Outputting the modified name and average grade
    std::cout << "Modified Name: " << student.getFirstName() << " " << student.getLastName() << std::endl;
    std::cout << "Modified Average Grade: " << student.getAverage() << std::endl;

    return 0;
}
