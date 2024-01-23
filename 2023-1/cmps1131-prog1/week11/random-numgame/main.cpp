#include <iostream>
#include <cstdlib>
#include <ctime>

void guessRanNum();

int main() {
    guessRanNum();
    return 0;
}

void guessRanNum() {
    int randomNum, userGuess, attempts;
    bool playAgain = true;

    // Seed for the random number generator
    std::srand(std::time(0));

    while (playAgain) {
        // Generate a random number between 1 and 100
        randomNum = std::rand() % 100 + 1;
        attempts = 0;

        std::cout << "I'm thinking of a number between 1 to 100...\n" << std::endl;

        while (true) {
            std::cout << "Guess what number it is: ";
            std::cin >> userGuess;

            attempts++;

            if (userGuess > randomNum) {
                std::cout << "Too high, try again!\n" << std::endl;
            } else if (userGuess < randomNum) {
                std::cout << "Too low, try again!\n" << std::endl;
            } else {
                std::cout << "Correct! You guessed the number in " << attempts << " tries.\n" << std::endl;

                char playAgainChoice;
                std::cout << "Do you want to play again? (y/n): ";
                std::cin >> playAgainChoice;
                std::cout << std::endl;

                if (playAgainChoice != 'y' && playAgainChoice != 'Y') {
                    playAgain = false;
                }

                // Exit the loop if the user doesn't want to play again
                break;
            }
        }
    }
}
