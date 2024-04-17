// Hangman Class Header

#ifndef PROG_SET1_HANGMAN_H
#define PROG_SET1_HANGMAN_H

#include "Player.h"
#include <vector>

class Hangman {
public:
    const static int ALPHABET_SIZE = 26; // num of rows for alphabet array
    const static int ASCII_ROWS = 7;
    const static int ASCII_COLS = 8;

    // constructor for the hangman class, initializes the game with a word list file and a username
    Hangman(const std::string& filename, const std::string& username);

    // function to prompt the user to select the game level and return the selected level
    int selectGameLevel();

    // function to generate a random number within the range of the word list size
    [[nodiscard]] int generateRandomNumber() const;

    // function to select a random word from the word list using the generated random number
    std::string selectRandomWord(int random_number);

    // function to load the word list from a file into the wordVector
    void loadWordList(const std::string& fileName);

    // function to start the game, includes the game loop and calls other game functions
    void startGame();

    // function to print a message with optional top and bottom borders
    void printMessage(const std::string&, bool printTop, bool printBottom) const;

    // function to draw the hangman ASCII art based on the guess count
    void drawHangman(int guessCount = 0) const;

    // function to reset the available letters to the full alphabet
    void resetAvailableLetters();

    // function to print an ASCII message, used for "YOU WIN!" and "GAME OVER!" messages
    void printAsciiMessage(std::string message);

    // function to print the available letters that have not been guessed yet
    void printAvailableLetters(const std::string& guessesSoFar);

    // function to check if the player has won by comparing the guessed letters with the word to guess
    bool checkWin(std::string wordToGuess, const std::string& guessesSoFar);

    // function to process the results of the game, print the game statistics, and ask the user to play again
    bool processResults(const std::string& wordToGuess, int guessAttempts, bool hasWon);

    // function to set the difficulty level and adjust the maximum allowed attempts accordingly
    void setDifficultyLevel(unsigned int diffLevel);

    // function to get the current difficulty level
    [[nodiscard]] unsigned getDifficultyLevel() const;

    // function to set the maximum allowed attempts based on the difficulty level
    void setMaxAllowedAttempts(unsigned allowedAttempts);

    // function to get the maximum allowed attempts
    [[nodiscard]] unsigned getMaxAllowedAttempts() const;

    // function to calculate the number of wrong guesses made so far
    unsigned attemptsMadeSoFar(const std::string& wordToGuess, std::string guessesSoFar);

private:
    Player player; // user playing the game
    std::vector<std::string> wordVector; // array of all words in the word list
    unsigned difficultyLevel; // determines the number of attempts allowed and range of word selection
    unsigned maxAllowedAttempts; // determined by difficultyLevel
    char alphabetArray[ALPHABET_SIZE + 1]; // array of all alphabet letters

    // ASCII representation that spells "YOU WIN!" and "GAME OVER!"
    constexpr static char G[ASCII_ROWS][ASCII_COLS] = {" ##### ", // Row=0
                                                       " #     ", // Row=1
                                                       " #     ", // Row=2
                                                       " # ### ", // Row=3
                                                       " #   # ", // Row=4
                                                       " #   # ", // Row=5
                                                       " ##### "}; // Row=6

    constexpr static char A[ASCII_ROWS][ASCII_COLS] {" ##### ",
                                                     " #   # ",
                                                     " #   # ",
                                                     " ##### ",
                                                     " #   # ",
                                                     " #   # ",
                                                     " #   # "};

    constexpr static char M[ASCII_ROWS][ASCII_COLS] {" #   # ",
                                                     " ## ## ",
                                                     " # # # ",
                                                     " #   # ",
                                                     " #   # ",
                                                     " #   # ",
                                                     " #   # "};

    constexpr static char E[ASCII_ROWS][ASCII_COLS] {" ##### ",
                                                     " #     ",
                                                     " #     ",
                                                     " ##### ",
                                                     " #     ",
                                                     " #     ",
                                                     " ##### "};

    constexpr static char O[ASCII_ROWS][ASCII_COLS] {" ##### ",
                                                     " #   # ",
                                                     " #   # ",
                                                     " #   # ",
                                                     " #   # ",
                                                     " #   # ",
                                                     " ##### "};

    constexpr static char V[ASCII_ROWS][ASCII_COLS] {" #   # ",
                                                     " #   # ",
                                                     " #   # ",
                                                     " #   # ",
                                                     " #   # ",
                                                     "  # #  ",
                                                     "   #   "};

    constexpr static char R[ASCII_ROWS][ASCII_COLS] {" ##### ",
                                                     " #   # ",
                                                     " #   # ",
                                                     " ##### ",
                                                     " # #   ",
                                                     " #  #  ",
                                                     " #   # "};

    constexpr static char Y[ASCII_ROWS][ASCII_COLS] {" #   # ",
                                                     "  # #  ",
                                                     "   #   ",
                                                     "   #   ",
                                                     "   #   ",
                                                     "   #   ",
                                                     "   #   "};

    constexpr static char U[ASCII_ROWS][ASCII_COLS] {" #   # ",
                                                     " #   # ",
                                                     " #   # ",
                                                     " #   # ",
                                                     " #   # ",
                                                     " #   # ",
                                                     " ##### "};

    constexpr static char W[ASCII_ROWS][ASCII_COLS] {" #   # ",
                                                     " #   # ",
                                                     " #   # ",
                                                     " #   # ",
                                                     " # # # ",
                                                     " ## ## ",
                                                     " #   # "};

    constexpr static char N[ASCII_ROWS][ASCII_COLS] {" #   # ",
                                                     " ##  # ",
                                                     " # # # ",
                                                     " #  ## ",
                                                     " #   # ",
                                                     " #   # ",
                                                     " #   # "};

    constexpr static char exclamation[ASCII_ROWS][ASCII_COLS] {"   #   ",
                                                               "   #   ",
                                                               "   #   ",
                                                               "   #   ",
                                                               "       ",
                                                               "   #   ",
                                                               "   #   "};

    constexpr static char space[ASCII_ROWS][ASCII_COLS] {"       ",
                                                         "       ",
                                                         "       ",
                                                         "       ",
                                                         "       ",
                                                         "       ",
                                                         "       "};

};

#endif //PROG_SET1_HANGMAN_H
