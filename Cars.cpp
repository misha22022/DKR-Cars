#include "Cars.h"
//#include <stdio.h>
//#include "sqlite3.h"
#include <algorithm>
#include <fstream>

Cars::Cars() {}

void Cars::addCar(const Car& car) {
    m_cars.push_back(car);
}

std::vector<Car> Cars::getCarsByModel(const std::string& model) const {
    std::vector<Car> result;
    for (const auto& car : m_cars) {
        if (car.getModel() == model) {
            result.push_back(car);
        }
    }
    return result;
}

std::vector<Car> Cars::getCarsByNameAndYears(const std::string& name, int years) const {
    std::vector<Car> result;
    for (const auto& car : m_cars) {
        if (car.getName() == name
            && (2024 - car.getYear()) < years) {
            result.push_back(car);
        }
    }
    return result;
}

std::vector<Car> Cars::getCarsByYearAndPrice(int year, double price) const {
    std::vector<Car> result;
    for (const auto& car : m_cars) {
        if (car.getYear() == year && car.getPrice() > price) {
            result.push_back(car);
        }
    }
    return result;
}

std::ostream& operator<<(std::ostream& os, const Cars& Cars) {
    for (const auto& car : Cars.m_cars) {
        os << car << std::endl;
    }
    return os;
}

void Cars::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& car : m_cars) {
            std::string line = car.toString();
            for (char& c : line) {
                c ^= 111;
            }
            file << line << std::endl;
        }
        file.close();
    }

//    void Cars::saveToDB(const sqlite3* db) const {
 //       char* err = 0;
 //     int i;
 //     String SQL = "INSERT INTO Cars (ID, name, model, year, color, price, num) ";
 //     for (const auto& car : m_cars) {
 //         SQL += car.toSQL + ";";
 //     }
 //     i = SQL.Length();
 //     SQL[i-1] = ' ';
        //const char* SQL = "CREATE TABLE IF NOT EXISTS foo(a,b,c); INSERT INTO FOO VALUES(1,2,3); INSERT INTO FOO SELECT * FROM FOO;";
 //     sqlite3_exec(db, SQL, 0, 0, &err);
 // }
}