#include <iostream>
#include <limits>
#include <fstream>
#include "tool.h"

int main() {
    std::cout << "\tQuestion 1:\n";
    std::cout << "-----------------------------" << std::endl;

    // write to file
    std::ofstream out{"words.txt", std::ios::out};

    if (!out) {
        std::cerr << "File could not be opened.\n";
        exit(1);
    }

    out << "cosa\n";
    out << "anno\n";
    out << "uomo\n";
    out << "casa\n";
    out << "vita\n";
    out.close();

    // replace and count vowels
    std::fstream replace{"words.txt", std::ios::in | std::ios::out | std::ios::binary};

    if (!replace) {
        std::cerr << "File could not be opened.\n";
        exit(1);
    }

    int vowels = 0;

    while (!replace.eof()) {
        int letter = replace.get();

        if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u') {
            replace.seekp(-1, std::ios::cur);
            vowels++;
            replace << '$';
        }
    }

    replace.close();
    std::cout << "Number of vowels: " << vowels << std::endl;

    std::cout << "\n\tQuestion 2:\n";
    std::cout << "-----------------------------" << std::endl;

    Tool tool;

    std::fstream file{"hardware.dat", std::ios::out | std::ios::binary};

    if (!file) {
        std::cerr <<"Error opening file."<< std::endl;
        exit(1);
    }

    while(true) {
        int record = 0;
        std::string nameTool = "";
        int quantity = 0;

        std::cout << "Enter the record # (Press -1 to end the program): ";
        std::cin >> record;

        if(record == -1) {
            break;
        }

        tool.setRecord(record);

        std::cout << "Enter the Tool Name: ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, nameTool);
        tool.setToolName(nameTool);

        std::cout << "Enter the Quantity: ";
        std::cin >> quantity;
        tool.setQuantity(quantity);

        std::cout << std::endl;

        file.write(reinterpret_cast<const char*>(&tool),sizeof(tool));
    }

    file.close();

    return 0;
}