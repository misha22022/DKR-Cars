//#pragma once
//class Cars
//{
//}
//#ifndef Cars_H
//#define Cars_H

#include "Car.h"
#include <vector>
#include <string>

class Cars {
private:
    std::vector<Car> m_cars;

public:
    Cars();

    void addCar(const Car& car);

    std::vector<Car> getCarsByModel(const std::string& name) const;

    std::vector<Car> getCarsByNameAndYears(const std::string& name, int years) const;

    std::vector<Car> getCarsByYearAndPrice(int year, double price) const;

    friend std::ostream& operator<<(std::ostream& os, const Cars& Cars);

    void saveToFile(const std::string& filename) const;
 //  void saveToDB(const sqlite3 db);
};

