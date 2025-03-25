// Чхобадзе Максиме Кахаберович ЭФБО-16-24

// 29. Класс "Фигура" и "Снежинка"
// Создайте базовый класс Shape с виртуальным методом area().
// Создайте производный класс Snowflake, который переопределяет метод
// для вычисления площади снежинки.
// Тестирование: Проверьте корректность вызова метода area() через
// указатель на базовый класс.

#include <iostream>
using namespace std;

class Shape {
public:
    virtual float area() {
        return 0;
    }
};

class Snowflake : public Shape {
public:
    float area() override {
        return 12.3; // некая константа
    }
};

int main() {
    Shape* shape = new Snowflake();
    cout << "Snowflake area: " << shape->area() << endl;
    delete shape;
    return 0;
}