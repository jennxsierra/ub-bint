#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using string = std::string; // Using directive to avoid typing std:: before string

class Student {
private:
    string firstName;
    string lastName;
    int examGrade1;
    int examGrade2;
    int examGrade3;

public:
    // Constructor
    Student(string fName, string lName, int grade1, int grade2, int grade3);

    // Getter and Setter functions for first name
    string getFirstName();
    void setFirstName(string fName);

    // Getter and Setter functions for last name
    string getLastName();
    void setLastName(string lName);

    // Getter and Setter functions for exam grades
    int getExamGrade1();
    void setExamGrade1(int grade);

    int getExamGrade2();
    void setExamGrade2(int grade);

    int getExamGrade3();
    void setExamGrade3(int grade);

    // Function to calculate and return the average of exam grades
    double getAverage();
};

#endif // STUDENT_H
