#include <iostream>
#include <string>
#include <fstream>
#include "city.h"

int main() {
    std::cout << "\tQuestion 1:\n";
    std::cout << "-----------------------------" << std::endl;

    std::ofstream studentFile("..\\student.txt", std::ios::out);

    if (!studentFile) {
        std::cerr << "File could not be opened." << std::endl;
        exit(1);
    }

    int students = 10;

    for(int i = 0; i < students; i++) {
        std::cout << "Enter Student ID: ";
        std::string studentID;
        std::getline(std::cin >> std::ws, studentID);
        studentFile << studentID << " ";

        std::cout << "Enter grade 1: ";
        double grade1;
        std::cin >> grade1;
        studentFile << grade1 << " ";

        std::cout << "Enter grade 2: ";
        double grade2;
        std::cin >> grade2;
        studentFile << grade2 << " ";

        std::cout << "Enter grade 3: ";
        double grade3;
        std::cin >> grade3;
        studentFile << grade3 << std::endl;

        std::cout << std::endl;
    }

    studentFile.close();

    std::cout << "\n\tQuestion 2:\n";
    std::cout << "-----------------------------" << std::endl;

    std::fstream file("..\\binfile.txt",std::ios::out | std::ios::binary);

    if(!file){
        std::cerr << "File could not be opened." << std::endl;
        exit(1);
    }

    City city{};
    char choice;

    while(true) {
        std::cout << "Do you want to enter a city? [Y/N]: ";
        std::cin >> choice;

        if(choice == 'n' || choice == 'N') {
            break;
        }

        std::cout << "\nEnter city name: ";
        std::string nameCity;
        std::getline(std::cin >> std::ws, nameCity);

        std::cout << "Enter population: ";
        int pop;
        std::cin >> pop;

        city.setCityName(nameCity);
        city.setPopulation(pop);

        file.write(reinterpret_cast<const char*>(&city), sizeof(city));

        std::cout << std::endl;
    }

    file.close();

    return 0;
}