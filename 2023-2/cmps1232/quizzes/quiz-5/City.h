#ifndef BINT_CITY_H
#define BINT_CITY_H

#include<iostream>
#include<string>

class City {
public:
    City();
    City(std::string, int);
    void setCityName(std::string);
    std::string getCityName();
    void setPopulation(int);
    [[nodiscard]] int getPopulation() const;

private:
    static void printDetails(const std::string&, int);
    std::string cityname;
    int population{};
};

#endif //BINT_CITY_H