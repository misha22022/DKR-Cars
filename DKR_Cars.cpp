// DKR_Cars.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
//#include <stdio.h>
//#include "sqlite3.h"
#include "Cars.h"
#include "Logger.h"
#include <iostream>

int main() {
    Cars Cars;

    Car car1(1, "Audi", "RS8", 2021, "Black", 40000.0, "BT0606IB");
    Car car2(2, "Mercedes-Benz", "E63", 2018, "White", 23000.0, "BT2202AA");
    Car car3(3, "BMW", "E34", 2005, "Green", 5000.0, "KA4565AA");

    Cars.addCar(car1);
    Cars.addCar(car2);
    Cars.addCar(car3);

    Logger logger("log.txt");

    //sqlite3* db = 0; // хэндл объекта соединение к БД
    //char* err = 0;

    // открываем соединение
    //if (sqlite3_open("..\..\cars.db", &db))
    //    logger.log(sqlite3_errmsg(db));
    //else {
    //    logger.log("Database not found");
    //}
    // выполняем SQL
    //else if (sqlite3_exec(db, SQL, 0, 0, &err))
    //{
      //fprintf(stderr, "Ошибка SQL: %sn", err);
      //sqlite3_free(err);
    //}
    // закрываем соединение
//    sqlite3_close(db);
  
 

    std::cout << "All cars:\n" << Cars << std::endl;

    std::string model = "E34";
    std::cout << "Cars model " << model << ":\n";
    std::vector<Car> carsByModel = Cars.getCarsByModel(model);
    for (const auto& car : carsByModel) {
        std::cout << car << std::endl;
    }

    std::string name = "Audi";
    int years = 5;
    std::cout << "Cars name " << name << " that no older than " << years << " years:\n";
    std::vector<Car> carsByNameAndYears = Cars.getCarsByNameAndYears(name, years);
    for (const auto& car : carsByNameAndYears) {
        std::cout << car << std::endl;
    }

    int year = 2021;
    double price = 5000.0;
    std::cout << "Cars with year " << year << " and price higher than " << price << ":\n";
    std::vector<Car> carsByYearAndPrice = Cars.getCarsByYearAndPrice(year, price);
    for (const auto& car : carsByYearAndPrice) {
        std::cout << car << std::endl;
    }

    Cars.saveToFile("cars.txt");
    logger.log("Cars saved to file.");

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
