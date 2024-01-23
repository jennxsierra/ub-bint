//Implementation of Miscellaneous Class

#include "Miscellaneous.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

void Miscellaneous::multiplication() {
    int correctAns = 0;
    int incorrectAns = 0;
    srand(time(nullptr)); //Seed for random number generator

    for (int i{0}; i < 10; ++i) {
        //Generate random number from 1 to 9
        //https://stackoverflow.com/a/4621216
        int num1 = rand() % 9 + 1;
        int num2 = rand() % 9 + 1;

        std::cout << "How much is " << num1 << " times " << num2 << "? ";
        int userAnswer;
        std::cin >> userAnswer;

        int attempts = 0; //Counter for incorrect answers

        //Incorrect answer procedure
        while (userAnswer != num1 * num2) {
            ++incorrectAns;
            int responseNum = rand() % 4 + 1;

            switch (responseNum) {
                case 1:
                    std::cout << "No. Please try again.\n" << std::endl;
                    break;
                case 2:
                    std::cout << "Wrong. Try once more.\n" << std::endl;
                    break;
                case 3:
                    std::cout << "Don't give up!\n" << std::endl;
                    break;
                case 4:
                    std::cout << "No. Keep trying.\n" << std::endl;
                    break;
            }
            //Allow user to try again, but checks if attempts exceed 10
            if (++attempts >= 10) {
                std::cout << "You have exceeded 10 attempts. The correct answer is " << num1 * num2 << ".\n";
                break;
            }

            std::cout << "How much is " << num1 << " times " << num2 << "? ";
            std::cin >> userAnswer;
        }

        //Ensures only 10 responses are recorded, even if user gets all incorrect
        if (attempts == 10) {
            i = 10;
        }

        //Correct answer procedure
        if (userAnswer == num1 * num2) {
            ++correctAns;
            int responseNum = rand() % 4 + 1;

            switch (responseNum) {
                case 1:
                    std::cout << "Very good!\n" << std::endl;
                    break;
                case 2:
                    std::cout << "Excellent!\n" << std::endl;
                    break;
                case 3:
                    std::cout << "Nice work!\n" << std::endl;
                    break;
                case 4:
                    std::cout << "Keep up the good work!\n" << std::endl;
                    break;
            }
        }
    }

    //Calculate percentage of correct answers
    double percentage = (static_cast<double>(correctAns - incorrectAns) / 10.0) * 100;
    std::cout << "Your percentage of correct responses is " << percentage << "%" << std::endl;

    //Less than 75%, suggest seeking extra help
    if (percentage < 75) {
        std::cout << "Please ask your instructor for extra help." << std::endl;
        return;
    }
}

void Miscellaneous::numberGuess() {
    //Seed for random number generator
    srand(time(nullptr));

    /* Implemented use of lambda function for valid guess verification
     * https://www.learncpp.com/cpp-tutorial/introduction-to-lambdas-anonymous-functions/ */
    auto isValidGuess = [](int guess) {
        return guess >= 1 && guess <= 1000;
    };

    while (true) {
        /*Random number between 1 and 1000
         * Number resets every time loop starts over*/
        int numToGuess = rand() % 1000 + 1;
        int guesses = 0;
        int guess;

        std::cout << "\nI have a number between 1 and 1000." << std::endl;
        std::cout << "Can you guess my number?" << std::endl;
        std::cout << "Please type your first guess: ";

        do {
            std::cin >> guess;
            guesses++;

            if (!isValidGuess(guess)) {
                std::cout << "Invalid guess. Please enter a number between 1 and 1000.\n" << std::endl;
            } else if (guess < numToGuess) {
                std::cout << "Too low. Try again.\n" << std::endl;
            } else if (guess > numToGuess) {
                std::cout << "Too high. Try again.\n" << std::endl;
            } else {
                std::cout << "Excellent! You guessed the number in " << guesses << " tries!" << std::endl;
                /*Based on the program set instructions,having exactly 10
                 *guesses produces 2 responses.*/
                if (guesses <= 10) {
                    std::cout << "Either you know the secret or you got lucky!\n";
                    if (guesses == 10) {
                        std::cout << "Ahah! You know the secret!\n";
                    }
                } else {
                    std::cout << "You should be able to do better!\n";
                }
            }
        } while (guess != numToGuess);

        //Asking the player if they want to play again
        std::cout << "\nWould you like to play again? (y or n): ";
        char playAgain;
        std::cin >> playAgain;

        if (playAgain != 'Y' && playAgain != 'y') {
            //Break the loop if player enters 'n' or 'N'
            break;
        }
    }
}

void Miscellaneous::printSquare() {
    int size;

    //Loop until valid size is entered
    while (true) {
        std::cout << "Enter the size of the side of the square (1 to 20): ";
        std::cin >> size;

        //Validation for size of side
        if (size>= 1 && size <= 20) {
            break;
        } else {
            //Error message for invalid size
            std::cout << "Invalid size. Please enter a size between 1 and 20.\n" << std::endl;
        }
    }

    //Outer loop for rows
    for (int i{1}; i <= size; ++i) {
        //Inner loop for columns
        for (int j{1}; j <= size; ++j) {
            /*Check if current position is at the border of the square
             * first or last row, first or last column*/
            if (i == 1 || i == size || j == 1 || j == size) {
                //Print '*' for border positions
                std::cout << "*";
            } else {
                //Print a space for inner positions
                std::cout << " ";
            }
        }
        //New line after each row is printed
        std::cout << std::endl;
    }
}

void Miscellaneous::calculatePayroll() {
    int payCode;

    //Display paycodes
    std::cout << "Employee Paycodes:\n"
                 "1 - Manager\n"
                 "2 - Hourly Worker\n"
                 "3 - Commission Worker\n"
                 "4 - Pieceworker\n" << std::endl;

    //Loop until valid paycode is entered
    while (true) {
        std::cout << "Enter employee paycode (5 to quit): ";
        std::cin >> payCode;

        //Switch statement for paycode
        switch (payCode) {
            case 1: {
                //Manager
                double salary;
                std::cout << "Enter weekly salary: $";
                std::cin >> salary;
                std::cout << "The manager's pay for this week is $" << salary << "\n\n";
                break;
            }
            case 2: {
                //Hourly
                double hoursWorked;
                double hourlyRate;
                std::cout << "Enter hours worked: ";
                std::cin >> hoursWorked;
                std::cout << "Enter hourly rate: $";
                std::cin >> hourlyRate;

                //Calculate pay
                double pay = hoursWorked * hourlyRate;

                //Check if overtime is applicable
                if (hoursWorked > 40) {
                    //Calculate overtime pay
                    pay += (hoursWorked - 40) * hourlyRate * 0.5;
                }

                std::cout << "The hourly worker's pay for this week is $" << pay << "\n\n";
                break;
            }
            case 3: {
                //Commission
                double weeklySales;
                std::cout << "Enter gross weekly sales: $";
                std::cin >> weeklySales;

                //Calculate pay
                double pay = 250 + (weeklySales * 0.057);

                std::cout << "The commission worker's pay for this week is $" << pay << "\n\n";
                break;
            }
            case 4: {
                //Pieceworker
                double wagePerPiece;
                int pieces;
                std::cout << "Enter wage per piece: $";
                std::cin >> wagePerPiece;
                std::cout << "Enter number of pieces: ";
                std::cin >> pieces;

                //Calculate pay
                double pay = wagePerPiece * pieces;

                std::cout << "The pieceworker's pay for this week is $" << pay << "\n\n";
                break;
            }
            case 5: {
                //Quit
                std::cout << "Thank you and have a nice day!" << std::endl;
                return;
            }

            default: {
                //Error message for invalid paycode
                std::cout << "Invalid paycode. Please enter a paycode between 1 and 5." << "\n\n";
            }
        }
    }
}