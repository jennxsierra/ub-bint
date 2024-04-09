#include <iostream>
#include <fstream>
#include <string>

std::string city;

int main() {
    std::cout << "Where do you live? ";
    std::cin >> city;

    std::ofstream output("..\\myFile.txt", std::ios::out);

    if (!output) {
        std::cerr << "File could not be opened." << std::endl;
        exit(1);
    } else {
        output << "I think you live in Belmopan.\n";
        output.close();
    }

    std::fstream inOut{"..\\myFile.txt", std::ios::in | std::ios::out};
    inOut.seekg(20, std::ios::beg);
    inOut << city;
    inOut.close();

    std::ifstream input("..\\myFile.txt", std::ios::in);

    if (!input) {
        std::cerr << "Error, could not open file." << std::endl;
        exit(1);
    } else {
        std::string word;
        while (input >> word) {
            std::cout << word << " ";
        }
        input.close();
    }

    return 0;
}
