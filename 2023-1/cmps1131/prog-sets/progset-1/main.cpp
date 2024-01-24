/* Jennessa Sierra
 * Principles of Programming
 * Assignment: Program Set 1 */
#include <iostream>
#include "Student.h"
#include "Converter.h"

void printStudent(const Student& stu);

int main() {
    Student s1{"John", "Doe"};
    printStudent(s1);

    s1.setFirstName("Jo");
    s1.setID("2020150000");
    s1.setDob("19/11/2019");
    s1.setGPA(4.1);
    s1.setGPA(-0.4);
    s1.setGPA(3.75);
    s1.setGender('j');
    s1.setGender(' ');
    s1.setGender('f');
    s1.setStatus('s');
    s1.setFirstName("j0hn");
    s1.setFirstName("John");
    s1.setLastName("Do3");
    s1.setLastName("Doe");
    printStudent(s1);

    Converter c;
    std::cout << "Generated Username from "<< s1.getFirstName() << " " <<s1.getLastName() << " is: "
              << c.generateUsername(s1.getFirstName(),s1.getLastName())<< std::endl;
    std::cout << "Title of person is: '" << c.getTitle(s1.getGender(),s1.getStatus())
              << "' based on gender of: '" << s1.getGender() << "' and status of '" << s1.getStatus() << "'" << std::endl;
    std::cout << "Letter grade for a GPA of: " << s1.getGPA() <<" is: '" << c.convertGPAtoGrade(s1.getGPA())
              << "'" << std::endl;

    return 0;
}

void printStudent(const Student& stu) {
    std::cout << "*******************************************" << std::endl;
    std::cout << "Student ID: " << stu.getID() << std::endl;
    std::cout << "Student first name: " << stu.getFirstName() << std::endl;
    std::cout << "Student last name: " << stu.getLastName() << std::endl;
    std::cout << "Student DOB: " << stu.getDob() << std::endl;
    std::cout << "Student gender: " << stu.getGender() << std::endl;
    std::cout << "Student status: " << stu.getStatus() << std::endl;
    std::cout << "Student GPA: " << stu.getGPA() << std::endl;
    std::cout << "*******************************************" << std::endl;
}