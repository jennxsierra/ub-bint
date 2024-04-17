// Player Class Header

#ifndef PROG_SET1_PLAYER_H
#define PROG_SET1_PLAYER_H

#include <string>

class Player {
public:
    // constructor for the Player class, initializes the player with a username and an optional difficulty level
    // marked as explicit to prevent implicit conversions
    explicit Player(const std::string& username, unsigned int level = 1);

    // function to set the difficulty level for the player
    void setDifficultyLevel(unsigned int level);

    // function to get the current difficulty level of the player
    [[nodiscard]] int getDifficultyLevel() const;

    // function to set the username for the player
    void setUsername(const std::string& name);

    // function to get the current username of the player
    std::string getUsername();

    // function to set the number of guesses for the player
    void setGuesses(unsigned int numGuesses);

    // function to generate a string containing the player's statistics
    std::string generateStatistics();

    // function to reset the player's guesses array
    void resetGuessesArray();

private:
    int guessesArray[10]; // keeps track of the 10 most recent player scores
    char username[20]; // stores the player's username
    unsigned int difficultyLevel; // player's chosen difficulty level
    static const unsigned int MAX_DIFFICULTY_LEVEL = 3; // maximum difficulty level allowed
};


#endif //PROG_SET1_PLAYER_H
