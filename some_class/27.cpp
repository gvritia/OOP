// Чхобадзе Максиме Кахаберович ЭФБО-16-24

// 27. Класс "Телефон"
// Создайте класс Phone, который представляет телефон. Класс должен
// содержать приватные поля для хранения модели, производителя и года
// выпуска. Добавьте методы для изменения и получения значений этих
// полей.
// Тестирование: Проверьте корректность работы методов для
// изменения и получения данных.

#include <iostream>
#include <string>

using namespace std;

class Phone {
private:
    string model;
    string manufacturer;
    int year;

public:
    Phone(string model, string manufacturer, int year) {
        this->model = model;
        this->manufacturer = manufacturer;
        this->year = year;
    }

    string get_model() {
        return model;
    }

    string get_manufacturer() {
        return manufacturer;
    }

    int get_year() {
        return year;
    }

    void set_model(string model) {
        this->model = model;
    }

    void set_manufacturer(string manufacturer) {
        this->manufacturer = manufacturer;
    }

    void set_year(int year) {
        this->year = year;
    }
};

int main() {
    // Создаем телефон
    Phone my_phone("nokia 3310", "Nokia", 2000);
    // Выводим исходные данные
    cout << "Initial phone data:" << endl;
    cout << "Model: " << my_phone.get_model() << endl;
    cout << "Manufacturer: " << my_phone.get_manufacturer() << endl;
    cout << "Year: " << my_phone.get_year() << endl;
    // Изменяем данные телефона
    my_phone.set_model("iPhone XS");
    my_phone.set_manufacturer("Apple");
    my_phone.set_year(2018);

    // Выводим измененные данные
    cout << "\nUpdated phone data:" << endl;
    cout << "Model: " << my_phone.get_model() << endl;
    cout << "Manufacturer: " << my_phone.get_manufacturer() << endl;
    cout << "Year: " << my_phone.get_year() << endl;
    return 0;
}
