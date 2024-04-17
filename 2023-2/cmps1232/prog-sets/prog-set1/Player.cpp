// Player Class Implementation

#include <string>
#include <iomanip> // for std::setprecision
#include "Player.h"

// constructor sets username and level, and resets guesses array
Player::Player(const std::string &username, unsigned int level) {
    setUsername(username);
    setDifficultyLevel(level);
    resetGuessesArray();
}

// implements ternary operator to check if level is within 1 and 3
void Player::setDifficultyLevel(unsigned int level) {
    difficultyLevel = (level < 1 || level > MAX_DIFFICULTY_LEVEL ) ? 1 : level;
}

// returns difficulty level
int Player::getDifficultyLevel() const {
    return static_cast<int>(difficultyLevel);
}

// sets username array characters
void Player::setUsername(const std::string &name) {
    std::size_t length = name.length();

    // only stores the first 19 characters of the username
    // one character is reserved for the null terminator
    if (length > 19) {
        length = 19;
    }

    for (int i = 0; i < length; ++i) {
        username[i] = name[i];
    }

    // appends null terminator
    username[length] = '\0';
}

// returns username
std::string Player::getUsername() {
    return username;
}


void Player::setGuesses(unsigned int numGuesses) {
    // use range-based for loop to iterate through guesses array to find zero value
    // https://en.cppreference.com/w/cpp/language/range-for
    for (int & i : guessesArray) {
        // if zero value is found, store score and return
        if (i == 0) {
            i = static_cast<int>(numGuesses);
            return;
        }
    }

    // if no zero value is found, reset the array and store score
    resetGuessesArray();
    guessesArray[0] = static_cast<int>(numGuesses);
}

// returns a string of the game statistics
std::string Player::generateStatistics() {
    std::string stats = "\t    Guesses: ";
    int count = 0;
    double sum = 0;

    // appends guesses to string and tracks sum and count
    for (int i : guessesArray) {
        if (i != 0) {
            stats += std::to_string(i) + " ";
            sum += i;
            count++;
        }
    }

    // calculates average and appends to string
    if (count > 0) {
        double average = sum / count;
        // uses ostringstream to format average to one decimal place
        // https://cplusplus.com/articles/D9j2Nwbp/
        std::ostringstream avgStream;
        avgStream << std::fixed << std::setprecision(1) << average;

        stats += "\n\tAverage Guesses: " + avgStream.str();
    }

    return stats;
}

// resets all values in guessesArray to zero
void Player::resetGuessesArray() {
    for (int & i : guessesArray) {
        i = 0;
    }
}