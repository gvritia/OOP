//https://contest.yandex.ru/contest/60944/problems/A/
#include <iostream>
#include <cmath>

using namespace std;
// virtual double square() = 0;
// → Заставляет наследников реализовать square(), делая Figure абстрактным классом.
// virtual ~Figure() {}
// → Позволяет корректно удалять объекты через указатели Figure*, предотвращая утечки памяти.
class Figure {
public:
    virtual double square() = 0;
};

class Triangle : public Figure {
private:
    double a, b, c;

public:
    Triangle(double a, double b, double c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    double square() {
        double p = (a + b + c) / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
};

class Rectangle : public Figure {
private:
    double a, b;

public:
    Rectangle(double a, double b) {
        this->a = a;
        this->b = b;
    }

    double square() {
        return a * b;
    }
};

class Trapezoid : public Figure {
private:
    double a, b, h;

public:
    Trapezoid(double a, double b, double h) {
        this->a = a;
        this->b = b;
        this->h = h;
    }

    double square() {
        return ((a + b) / 2) * h;
    }
};
