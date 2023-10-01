#include <iostream>
using namespace std;

string printLetterGrade(int score);

int main() {

    int score1 = 93;
    int score2 = 67;
    int score3 = 120;

    cout << "Your letter grade is: " << printLetterGrade(score1) << endl;
    cout << "Your letter grade is: " << printLetterGrade(score2) << endl;
    cout << "Your letter grade is: " << printLetterGrade(score3) << endl;

    return 0;
}

string printLetterGrade(int score) {
    if (score >= 0 && score <= 100) {
        if (score >= 95) {
            return "A+";
        } else if (score >= 90) {
            return "A";
        } else if (score >= 85) {
            return "B+";
        } else if (score >= 80) {
            return "B";
        } else if (score >= 75) {
            return "C+";
        } else if (score >= 70) {
            return "C";
        } else if (score >= 65) {
            return "D+";
        } else if (score >= 60) {
            return "D";
        } else {
            return "F";
        }
    } else {
        return "Grade specified is not valid";
    }
}