// Чхобадзе Максиме Кахаберович ЭФБО-16-24

// 28. Класс "Музыкальный инструмент" и "Гитара"
// Создайте базовый класс MusicalInstrument с полями brand и type.
// Создайте производный класс Guitar, который добавляет поле numStrings.
// Добавьте метод для вывода информации о гитаре.
// Тестирование: Проверьте корректность вывода информации для
// объектов класса Guitar.

#include <iostream>
#include <string>
using namespace std;

class MusicalInstrument {
protected:
    string brand;
    string type;

public:
    MusicalInstrument(string brand, string type) {
        this->brand = brand;
        this->type = type;
    }
};


class Guitar : public MusicalInstrument{
private:
    int numStrings;

public:
    Guitar(string brand, int numStrings) : MusicalInstrument(brand, "Guitar"){
        this->numStrings = numStrings;
    }

    void show_info() {
        cout << "Brand: " << brand << endl;
        cout << "Type: " << type << endl;
        cout << "Number of strings: " << numStrings << endl;
    }
};

int main() {
    Guitar my_guitar("Fender", 6);
    my_guitar.show_info();
    cout << endl;
    Guitar anotherGuitar("Gibson", 12);
    anotherGuitar.show_info();
    return 0;
}
