#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using string = std::string; // Using directive to avoid typing std:: before string

class Student {
private:
    string firstName;
    string lastName;
    int examGrade1{};
    int examGrade2{};
    int examGrade3{};

public:
    // Constructor
    Student(string fName, string lName, int grade1, int grade2, int grade3);

    // Getter and Setter functions for first name
    [[nodiscard]] string getFirstName() const;
    void setFirstName(string fName);

    // Getter and Setter functions for last name
    [[nodiscard]] string getLastName() const;
    void setLastName(string lName);

    // Getter and Setter functions for exam grades
    [[nodiscard]] int getExamGrade1() const;
    void setExamGrade1(int grade1);

    [[nodiscard]] int getExamGrade2() const;
    void setExamGrade2(int grade2);

    [[nodiscard]] int getExamGrade3() const;
    void setExamGrade3(int grade3);

    // Function to calculate and return the average of exam grades
    [[nodiscard]] double getAverage() const;
};

#endif // STUDENT_H
