//Converter Class Definition

/* The Converter Class comprises function members designed to
 * enhance the functionality of the Student Class */

#ifndef PROGRAMSET1_CONVERTER_H
#define PROGRAMSET1_CONVERTER_H

#include <string>

class Converter {

private:

public:
    //Function Members
    //Returns username in the format "JDoe"
    std::string generateUsername(std::string fn, const std::string& ln);

    //Returns title (Ms., Mrs., Mr.)
    std::string getTitle(char gender, char status);

    //Returns letter grade based on GPA
    std::string convertGPAtoGrade (float gpa);
};

#endif //PROGRAMSET1_CONVERTER_H
