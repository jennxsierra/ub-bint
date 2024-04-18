// Hangman Class Implementation

#include "Hangman.h"
#include <iostream>
#include <string>
#include <fstream> // for file input/output
#include <limits> // for numeric_limits
#include <random> // for mt19937 and random_device
#include <ctime> // for time
#include <algorithm> // for transform

// definition of the static member variables
// avoids the ODR (One Definition Rule) violation
// https://en.cppreference.com/w/cpp/language/definition
constexpr char Hangman::G[ASCII_ROWS][ASCII_COLS];
constexpr char Hangman::A[ASCII_ROWS][ASCII_COLS];
constexpr char Hangman::M[ASCII_ROWS][ASCII_COLS];
constexpr char Hangman::E[ASCII_ROWS][ASCII_COLS];
constexpr char Hangman::O[ASCII_ROWS][ASCII_COLS];
constexpr char Hangman::V[ASCII_ROWS][ASCII_COLS];
constexpr char Hangman::R[ASCII_ROWS][ASCII_COLS];
constexpr char Hangman::Y[ASCII_ROWS][ASCII_COLS];
constexpr char Hangman::U[ASCII_ROWS][ASCII_COLS];
constexpr char Hangman::W[ASCII_ROWS][ASCII_COLS];
constexpr char Hangman::N[ASCII_ROWS][ASCII_COLS];
constexpr char Hangman::exclamation[ASCII_ROWS][ASCII_COLS];
constexpr char Hangman::space[ASCII_ROWS][ASCII_COLS];

Hangman::Hangman(const std::string& filename, const std::string& username) : player(username) {
    // loads the word list
    loadWordList(filename);

    // sets the difficulty level
    player.setDifficultyLevel(selectGameLevel());
}

int Hangman::selectGameLevel() {
    int diffLevel = {};

    // loops until a valid choice is made
    while (true) {
        // clears the screen
        system("cls");

        // displays the menu
        std::cout << "\t+-----------------------------------------+" << std::endl;
        std::cout << "\t| HANGMAN GAME CREATED BY JENNESSA SIERRA |" << std::endl;
        std::cout << "\t+-----------------------------------------+\n" << std::endl;

        std::cout << "\t[1] Easy\t [2] Medium\t [3] Hard\n" << std::endl;
        std::cout << "Choose a difficulty level: ";
        std::cin >> diffLevel;

        // checks if the input is valid
        if (!std::cin) {
            // clear the error flags
            std::cin.clear();
            // ignores the rest of the line
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            continue;
        }

        // checks if the input is within valid range
        if (diffLevel > 3 || diffLevel < 1) {
            continue;
        }

        // removes any additional input
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // sets difficultyLevel for the Hangman object
        setDifficultyLevel(diffLevel);

        // returns the chosen difficulty level
        return diffLevel;
    }
}

int Hangman::generateRandomNumber() const {
    // create a random device to seed the mersenne twister pseudo-random generator
    // https://en.cppreference.com/w/cpp/numeric/random/mersenne_twister_engine
    std::random_device rd;

    // ensure the random number is different each time the program is run
    // non-static member function time() is used to get the current calendar time
    std::seed_seq seed{rd(), static_cast<unsigned int>(time(nullptr))};

    // create a mersenne twister pseudo-random generator
    std::mt19937 gen(seed);

    // get the difficulty level
    unsigned diffLevel = getDifficultyLevel();

    // define the range based on the difficulty level
    int start, end;
    if (diffLevel == 1) {
        start = 0;
        end = 63;
    } else if (diffLevel == 2) {
        start = 64;
        end = 351;
    } else { // diffLevel == 3
        start = 352;
        end = 485;
    }

    // creates a uniform distribution of integers within the defined range
    std::uniform_int_distribution<int> numGen(start, end);

    // returns a random number
    return numGen(gen);
}

std::string Hangman::selectRandomWord(int random_number) {
    return wordVector[random_number];
}

void Hangman::loadWordList(const std::string& fileName) {
    std::string word;

    std::ifstream infile; // creates a file inputstream object used to connect to a text file
    infile.open (fileName); // use the inputstream object to open file

    if (infile.is_open()) { // check if the file was successfully opened
        while(!infile.eof()) { // while not at the end of file eof()
            getline(infile, word); // read a line from the file and store it in the string variable, word
            wordVector.push_back(word); // insert string word into the vector
        } // repeat until the end of file is reached

        infile.close(); // close the file once it has been processed
    } else { // if you are here, it is because there was a problem opening the file
        std::cout << "Unable to open file, " << fileName << std::endl; // notify the user that a problem has occurred
        std::cout << "Hangman game will now terminate." << std::endl;

        std::exit(-1); // terminate the program since no words could be loaded, making the game impossible
    }
}

void Hangman::startGame() {
    std::string lettersGuessed; // set of all letters guessed so far
    std::string ranWord; // random word the player has to guess
    int totalGuessCount; // total number of guesses so far
    bool hasWon; // whether the player has won
    bool playAgain; // whether the player wants to play again
    char guess{}; // current letter guess made by the player

    // did not use srand() as specified in the project requirements since
    // generateRandomNumber() resets the seed each time it is called

    // loop to play the game
    do {
        // initialize variables
        lettersGuessed = "";
        ranWord = "";
        totalGuessCount = 0;

        // generate random word
        int randomNumber{generateRandomNumber()};
        ranWord = selectRandomWord(randomNumber);

        resetAvailableLetters();

        // loop to output the hangman game
        do {
            system("cls"); // clear the screen
            printMessage("HANGMAN", true, true); // print the message "HANGMAN"
            drawHangman(totalGuessCount); // draw the hangman
            printAvailableLetters(lettersGuessed); // print the available letters
            printMessage("Guess the word", true, true); // print the message "Guess the word"

            hasWon = checkWin(ranWord, lettersGuessed);

            // if the player has won, break out of the loop
            if (hasWon) {
                break;
            }

            std::cout << "\nEnter guess: ";
            std::cin >> guess;

            // user cannot guess a non-alphabetic character
            // https://en.cppreference.com/w/cpp/string/byte/isalpha
            if (!(std::isalpha(guess))) {
                continue;
            }

            // remove any additional input that may have been entered
            // https://en.cppreference.com/w/cpp/io/basic_istream/ignore
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            // convert guess letter to uppercase using toupper()
            // https://en.cppreference.com/w/cpp/string/byte/toupper
            guess = static_cast<char>(std::toupper(guess));

            if (lettersGuessed.find(guess) == std::string::npos) {
                // append the guess to lettersGuessed if it is not already there
                lettersGuessed += guess;
            } else {
                // if the guess is already in lettersGuessed, continue to the next iteration
                continue;
            }

            // increment the totalGuessCount
            totalGuessCount = static_cast<int>(attemptsMadeSoFar(ranWord, lettersGuessed));


        } while (totalGuessCount < static_cast<int>(getMaxAllowedAttempts()));

        // process the results
        playAgain = processResults(ranWord, totalGuessCount, hasWon);

    } while (playAgain);

    system("cls");
    std::cout << "\t\t\t\t  +-----------------------------------------+" << std::endl;
    std::cout << "\t\t\t\t  | HANGMAN GAME CREATED BY JENNESSA SIERRA |" << std::endl;
    std::cout << "\t\t\t\t  +-----------------------------------------+\n" << std::endl;

    std::cout << R"(
          ________                __           ____                    __            _                __
         /_  __/ /_  ____ _____  / /_______   / __/___  _____   ____  / /___ ___  __(_)___  ____ _   / /
          / / / __ \/ __ `/ __ \/ //_/ ___/  / /_/ __ \/ ___/  / __ \/ / __ `/ / / / / __ \/ __ `/  / /
         / / / / / / /_/ / / / / ,< (__  )  / __/ /_/ / /     / /_/ / / /_/ / /_/ / / / / / /_/ /  /_/
        /_/ /_/ /_/\__,_/_/ /_/_/|_/____/  /_/  \____/_/     / .___/_/\__,_/\__, /_/_/ /_/\__, /  (_)
                                                            /_/            /____/        /____/
    )" << std::endl;
    system("pause");
    std::getchar();
}

void Hangman::printMessage(const std::string& message, bool printTop, bool printBottom) {
    // initialize the width of the game board
    const std::size_t length = 33;

    // print the top border
    if (printTop) {
        std::cout << "+";
        for (std::size_t i{0}; i < length; ++i) {
            std::cout << "-";
        }
        std::cout << "+" << std::endl;
    }

    std::cout << "|";

    // calculate the number of spaces needed to center the message
    std::size_t msgLen = message.size();
    std::size_t spaces = (length - msgLen) / 2;

    // print the left padding
    for (std::size_t i{0}; i < spaces; ++i) {
        std::cout << " ";
    }

    // print the message
    std::cout << message;

    // print the right padding
    for (std::size_t i{0}; i < spaces; ++i) {
        std::cout << " ";
    }

    // if the message length is even, add an extra space
    if (msgLen % 2 == 0) {
        std::cout << " ";
    }

    std::cout << "|";

    // print the bottom border
    if (printBottom) {
        std::cout << std::endl;
        std::cout << "+";
        for (std::size_t i{0}; i < length; ++i) {
            std::cout << "-";
        }
        std::cout << "+";
    }

    std::cout << std::endl;
}

void Hangman::drawHangman(int guessCount) const {
    int printCount = 1; // used to keep track of the number of body parts to print
    // constants to define the number of rows and body parts for the hangman
    const int hangmanParts = 8;
    const int hangmanRows = 4;
    // calculate the length of the noose based on the difficulty level
    // diffLevel 1 and 3 have maxAllowedAttempts of 10, diffLevel 2 has 13
    const std::size_t nooseLength = getMaxAllowedAttempts() - hangmanParts;

    // nooseLength for diffLevel 1 and 3 is 2
    // nooseLength for diffLevel 2 is 5
    for (int i = 0; i < nooseLength; ++i) {
        if (guessCount == 0) {
            printMessage("", false, false);
        } else {
            printMessage("|", false, false);
            --guessCount;
        }
    }

    // loop to print the hangman body parts
    // based on the number of incorrect guesses
    for (int i = 0; i < hangmanRows; ++i) {
        if (printCount <= guessCount) {
            if (printCount == 1) {
                printMessage("O", false, false);

                if (guessCount == 1 || guessCount == 2) {
                    ++printCount;
                } else if (guessCount == 3) {
                    printCount += 2;
                } else if (guessCount > 3) {
                    printCount += 3;
                }

                continue;
            }

            if (printCount == 2 || printCount == 6) {
                printMessage("/  ", false, false);
                ++printCount;
                continue;
            }

            if (printCount == 3) {
                printMessage("/| ", false, false);
                ++printCount;
                continue;
            }

            if (printCount == 4) {
                printMessage("/|\\", false, false);
                ++printCount;
                continue;
            }

            if (printCount == 5) {
                printMessage(" | ", false, false);

                if (guessCount == 5 || guessCount == 6) {
                    ++printCount;
                } else if (guessCount == 7) {
                    printCount += 2;
                }

                continue;
            }

            if (printCount == 7) {
                printMessage("/ \\", false, false);
                ++printCount;
                continue;
            }
        } else {
            // print empty lines if the player has not made any incorrect guesses
            printMessage("", false, false);
        }
    }
}

void Hangman::resetAvailableLetters() {
    // loop to initialize alphabetArray to contain all capital letters
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        alphabetArray[i] = static_cast<char>('A' + i);
    }

    // set the last element to the null terminator
    alphabetArray[ALPHABET_SIZE] = '\0';
}

void Hangman::printAsciiMessage(std::string message) {
    unsigned length = message.size();

    std::cout << std::endl;

    // loop through the message
    for (std::size_t i{0}; i < ASCII_ROWS; ++i) {
        for (std::size_t j{0}; j < length; ++j) {
            // switch statement to print the corresponding ASCII character
            switch (message[j]) {
                case 'G':
                    std::cout << G[i];
                    break;
                case 'A':
                    std::cout << A[i];
                    break;
                case 'M':
                    std::cout << M[i];
                    break;
                case 'E':
                    std::cout << E[i];
                    break;
                case 'O':
                    std::cout << O[i];
                    break;
                case 'V':
                    std::cout << V[i];
                    break;
                case 'R':
                    std::cout << R[i];
                    break;
                case 'Y':
                    std::cout << Y[i];
                    break;
                case 'U':
                    std::cout << U[i];
                    break;
                case 'W':
                    std::cout << W[i];
                    break;
                case 'N':
                    std::cout << N[i];
                    break;
                case '!':
                    std::cout << exclamation[i];
                    break;
                case ' ':
                    std::cout << space[i];
                    break;
                default:
                    break;
            }
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;
}


void Hangman::printAvailableLetters(const std::string& guessesSoFar) {
    printMessage("Available Letters", true, false);

    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        // use find() to check if the letter has been guessed
        if (guessesSoFar.find(alphabetArray[i]) != std::string::npos) {
            alphabetArray[i] = ' ';
        }
    }

    // convert alphabetArray to a string
    std::string availableLetters(alphabetArray);

    // print the available letters
    printMessage(availableLetters, true, false);
}

bool Hangman::checkWin(std::string wordToGuess, const std::string& guessesSoFar) {
    // use transform to convert wordToGuess to uppercase
    std::transform(wordToGuess.begin(), wordToGuess.end(), wordToGuess.begin(), ::toupper);

    // create a temporary string variable
    std::string revealedWord;

    bool allLettersGuessed = true;

    // use a range-based for loop to iterate through the wordToGuess
    for (char c : wordToGuess) {
        if (guessesSoFar.find(c) != std::string::npos) {
            revealedWord += c;
            revealedWord += " ";
        } else {
            revealedWord += "_ ";
            allLettersGuessed = false;
        }
    }

    // print the message
    printMessage(revealedWord, true, true);

    // if all the letters from wordToGuess have been guessed, return true
    return allLettersGuessed;
}

bool Hangman::processResults(const std::string& wordToGuess, int guessAttempts, bool hasWon) {
    // call the player object's setGuesses() function
    player.setGuesses(guessAttempts);

    // check if the player has won
    if (hasWon) {
        printAsciiMessage("YOU WON!");
    } else {
        printAsciiMessage("GAME OVER!");
    }

    std::cout << "\nThe correct word was: " << wordToGuess << "\n" << std::endl;

    std::cout << "      " << player.getUsername() << "'s Hangman Game Statistics:\n";
    std::cout << "------------------------------------------\n";

    // generate and print statistics
    std::string statistics = player.generateStatistics();
    std::cout << statistics << std::endl;

    std::cout << "------------------------------------------\n" << std::endl;

    std::cout << "NOTE: The lower your score, the better!\n"
                 "These scores reset every 10 games!\n"
                 "A perfect game won't be counted!\n" << std::endl;


    while (true) {
        // ask the user if they want to play again
        char playAgain;
        std::cout << "Do you want to play again? (Y/N): ";
        std::cin >> playAgain;

        // if the player chooses to play again
        if (playAgain == 'Y' || playAgain == 'y') {
            // call selectGameLevel() and set the difficulty level
            int diffLevel = selectGameLevel();
            player.setDifficultyLevel(diffLevel);

            return true;
        } else if (playAgain == 'N' || playAgain == 'n') {
            return false;
        } else {
            std::cout << "Invalid input. Please enter Y or N." << std::endl;
        }
    }
}

void Hangman::setDifficultyLevel(unsigned int diffLevel) {
    difficultyLevel = (diffLevel < 1 || diffLevel > 3 ) ? 1 : diffLevel;

    if (difficultyLevel == 1 || difficultyLevel == 3) {
        setMaxAllowedAttempts(10);
    } else { // if difficultyLevel is 2
        setMaxAllowedAttempts(13);
    }
}

unsigned Hangman::getDifficultyLevel() const {
    return difficultyLevel;
}

void Hangman::setMaxAllowedAttempts(unsigned allowedAttempts) {
    maxAllowedAttempts = allowedAttempts;
}

unsigned Hangman::getMaxAllowedAttempts() const {
    return maxAllowedAttempts;
}

unsigned Hangman::attemptsMadeSoFar(const std::string& wordToGuess, std::string guessesSoFar) {
    std::size_t guessLen = guessesSoFar.length();
    unsigned attempts = 0;

    // used find() to check if the guess is in the wordToGuess
    // used tolower() to convert the guess to lowercase since wordlist.txt contains all lowercase words
    // https://en.cppreference.com/w/cpp/string/byte/tolower
    for (std::size_t i = 0; i < guessLen; ++i) {
        if (wordToGuess.find(static_cast<char>(std::tolower(guessesSoFar[i]))) == std::string::npos) {
            ++attempts;
        }
    }

    return attempts;
}