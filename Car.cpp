#include "Car.h"
#include <iostream>

Car::Car(int id, const std::string& name, const std::string& model, int year, const std::string& color, double price, const std::string& num)
    : m_id(id), m_name(name), m_model(model), m_year(year), m_color(color), m_price(price), m_num(num) {}

int Car::getId() const {
    return m_id;
}

std::string Car::getName() const {
    return m_name;
}

std::string Car::getModel() const {
    return m_model;
}

int Car::getYear() const {
    return m_year;
}

std::string Car::getColor() const {
    return m_color;
}

double Car::getPrice() const {
    return m_price;
}

std::string Car::getnum() const {
    return m_num;
}

void Car::setId(int id) {
    m_id = id;
}

void Car::setName(const std::string& name) {
    m_name = name;
}

void Car::setModel(const std::string& model) {
    m_model = model;
}

void Car::setYear(int year) {
    m_year = year;
}

void Car::setColor(const std::string& color) {
    m_color = color;
}

void Car::setPrice(double price) {
    m_price = price;
}

void Car::setnum(const std::string& num) {
    m_num = num;
}

std::string Car::toString() const {
    return "ID: " + std::to_string(m_id) +
        "\nname: " + m_name +
        "\nModel: " + m_model +
        "\nYear: " + std::to_string(m_year) +
        "\nColor: " + m_color +
        "\nPrice: " + std::to_string(m_price) +
        "\nRegistration Number: " + m_num;
}
std::string Car::toSQL() const {
    return "(" + std::to_string(m_id) +
        ",'" + m_name + "'" +
        ",'" + m_model + "'" +
        "," + std::to_string(m_year) +
        ",'" + m_color + "'" +
        "," + std::to_string(m_price) +
        ",'" + m_num +"')";
}

std::ostream& operator<<(std::ostream& os, const Car& car) {
    os << car.toString() << std::endl;
    return os;
}