//Implementation of Student Class

#include "Student.h"
#include <algorithm>

//Parameterized Constructor Fxn to initialize data members
Student::Student(const std::string& fn, const std::string& ln) {
    setFirstName(fn);
    setLastName(ln);
    setDob("01/01/1900");
    setID("1000000001");
    setGPA(0.0);
    setGender('m');
    setStatus('m');
}

//Getter and Setter Fxn for firstName
const std::string& Student::getFirstName() const {
    return  firstName;
}
void Student::setFirstName(const std::string& fn) {
    //Implemented ternary to set firstName to an empty string, if it contains a number
    firstName = std::any_of(fn.begin(), fn.end(), ::isdigit) ? " " : fn;
}

//Getter and Setter Fxn for lastName
const std::string& Student::getLastName() const {
    return  lastName;
}
void Student::setLastName (const std::string& ln) {
    //Implemented ternary to set lastName to an empty string, if it contains a number
    lastName = std::any_of(ln.begin(), ln.end(), ::isdigit) ? " " : ln;
}

//Getter and Setter Fxn for DOB
const std::string& Student::getDob() const {
    return dob;
}
void Student::setDob(const std::string& dob1) {
    dob = dob1;
}

//Getter and Setter Fxn for ID
const std::string& Student::getID() const {
    return id;
}
void Student::setID(const std::string& id1) {
    id = id1;
}

//Getter and Setter Fxn for GPA
float Student::getGPA() const {
    return gpa;
}
void Student::setGPA(float gpa1) {
    //Implemented ternary to set gpa to 0, if it is outside 0-4
    gpa = (gpa1 < 0 || gpa1 > 4) ? 0 : gpa1;
}

//Getter and Setter Fxn for Gender
char Student::getGender() const {
    return gender;
}
void Student::setGender(char gender1) {
    //Implemented ternary to set gender to 'm', if char entered isn't either 'm' or 'f'
    gender = (gender1 == 'm' || gender1 == 'f') ? gender1 : 'm';
}

//Getter and Setter Fxn for Status
char Student::getStatus() const {
    return status;
}
void Student::setStatus(char status1) {
    //Implemented ternary to set status to 's', if char entered isn't either 'm' or 's'
    status = (status1 == 's' || status1 == 'm') ? status1 : 's';
}