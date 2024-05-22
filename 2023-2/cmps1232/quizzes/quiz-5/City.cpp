#include "City.h"

City::City() = default;

City::City(std::string nameCity,int pop) {
    setCityName(nameCity);
    setPopulation(pop);
}

void City::setCityName(std::string nameCity) {
        cityname = nameCity;
}

std::string City::getCityName(){
    return cityname;
}

void City::setPopulation(int pop) {
        if(pop < 0) {
            std::cout << "Error: Population cannot be negative." << std::endl;
        } else {
            population = pop;
        }
}

int City::getPopulation() const {
    return population;
}

void City::printDetails(const std::string& nameCity, int pop) {
    std::cout << "The name of the city is " << nameCity << std::endl;
    std::cout << "The population of " << nameCity << " is " << pop;
}