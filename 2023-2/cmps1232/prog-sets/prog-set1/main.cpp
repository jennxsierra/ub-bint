#include <iostream>
#include <string>
#include "Hangman.h"

int main() {
    std::cout << "\t+-----------------------------------------+" << std::endl;
    std::cout << "\t| HANGMAN GAME CREATED BY JENNESSA SIERRA |" << std::endl;
    std::cout << "\t+-----------------------------------------+\n" << std::endl;

    // prompt the user to enter their username
    std::string username;
    std::cout << "Enter your username [19 characters max]: ";

    // use std::ws to ignore leading whitespace
    std::getline(std::cin >> std::ws, username);

    // create a hangman game object
    Hangman game{"..\\wordlist.txt", username};

    // start the game
    game.startGame();

    return 0;
}