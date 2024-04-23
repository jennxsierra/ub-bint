#include <iostream>
#include <fstream>

int main() {
    // write to file
    std::ofstream out{"..\\replaceFile.txt", std::ios::out};

    if (!out) {
        std::cerr << "File could not be opened.\n";
        exit(1);
    }

    out << "I think you live in Belmopan\n";
    out << "Is that right?\n";
    out.close();

    // replace 'i' with '$'
    std::fstream replace{"..\\replaceFile.txt", std::ios::in | std::ios::out | std::ios::binary};

    if (!replace) {
        std::cerr << "File could not be opened.\n";
        exit(1);
    }

    while (!replace.eof()) {
        int letter = replace.get();

        if (letter == 'i' || letter == 'I') {
            replace.seekp(-1, std::ios::cur);
            std::cout << ' ' << replace.tellg();
            replace << '$';
        }
    }

    replace.close();

    return 0;
}