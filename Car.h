
#include <string>

class Car {
private:
    int m_id;
    std::string m_name;
    std::string m_model;
    int m_year;
    std::string m_color;
    double m_price;
    std::string m_num;

public:
    Car(int id, const std::string& name, const std::string& model, int year, const std::string& color, double price, const std::string& num);

    int getId() const;
    std::string getName() const;
    std::string getModel() const;
    int getYear() const;
    std::string getColor() const;
    double getPrice() const;
    std::string getnum() const;

    void setId(int id);
    void setName(const std::string& name);
    void setModel(const std::string& model);
    void setYear(int year);
    void setColor(const std::string& color);
    void setPrice(double price);
    void setnum(const std::string& num);

    std::string toString() const;
    std::string toSQL() const;
    friend std::ostream& operator<<(std::ostream& os, const Car& car);
};


