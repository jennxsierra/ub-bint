//Student Class Definition

/* The Student Class comprises data members that represent attributes
 * of a student object, alongside getters and setters for each */

/* Implemented the use of constant reference parameters to avoid
 * making an expensive copy of string objects */

/* Implemented the use of const at the end of function declaration
 * to indicate that the function does not modify the object's state
 * and ensure data integrity*/

/* Implemented the use of [[nodiscard]] attribute specifier to indicate
 * that the return value of the function should not be ignored */

#ifndef PROGRAMSET1_STUDENT_H
#define PROGRAMSET1_STUDENT_H

#include <string>

class Student {

private:
    //Data Members
    std::string firstName;
    std::string lastName;
    std::string dob; //date of birth
    std::string id; //student id
    float gpa{}; //grade point average
    char gender{}; //student's sex
    char status{}; //student's marital status

public:
    //Parameterized Constructor that sets firstName & lastName to empty strings
    explicit Student(const std::string& fn = "", const std::string& ln = "");
    /* Implemented use of explicit constructor to ensure that the constructor
    * is only used when the argument types match exactly */

    //Function Members
    //Getter and Setter for firstName
    [[nodiscard]] const std::string& getFirstName() const;
    void setFirstName(const std::string& fn);

    //Getter and Setter for lastName
    [[nodiscard]] const std::string& getLastName() const;
    void setLastName(const std::string& ln);

    //Getter and Setter for dob
    [[nodiscard]] const std::string& getDob() const;
    void setDob(const std::string& dob1);

    //Getter and Setter for id
    [[nodiscard]] const std::string& getID() const;
    void setID(const std::string& id1);

    //Getter and Setter for gpa
    [[nodiscard]] float getGPA() const;
    void setGPA(float gpa1);

    //Getter and Setter for gender
    [[nodiscard]] char getGender() const;
    void setGender(char gender1);

    //Getter and Setter for status
    [[nodiscard]] char getStatus() const;
    void setStatus(char status1);
};

#endif //PROGRAMSET1_STUDENT_H
