#include <iostream>
#include <cmath>
#include <math.h>
#include <algorithm>
#define _USE_MATH_DEFINES

using namespace std;

class Triangle {
public:
    double a, b, c;

    Triangle(double a, double b, double c) {
        this->a = a;
        this->b = b;
        this->c = c;
        if (exst_tr() == 0) {
            this->a = 3;
            this->b = 4;
            this->c = 5;
        }
    }

    bool exst_tr() {
        if (a + b <= c or a + c <= b or c + b <= a) {
            return false;
        }
        else {
            return true;
        }
    }

    void show() {
        cout << "A = " << a << ", B = " << b << ", C = " << c << endl;
    }

    double perimetr() {
        return a + b + c;
    }

    double square() {
        double p = (a + b + c) / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

    bool is_similar(Triangle &t2) {
        double sides1[3] = {a, b, c};
        double sides2[3] = {t2.a, t2.b, t2.c};

        sort(sides1, sides1 + 3);
        sort(sides2, sides2 + 3);

        return (sides1[0] / sides2[0] == sides1[1] / sides2[1]) &&
               (sides1[1] / sides2[1] == sides1[2] / sides2[2]);
    }

    double get_a() {
        return a;
    }

    double get_b() {
        return b;
    }

    double get_c() {
        return c;
    }
};


class Circle {
public:
    float r, x, y;;
    Circle(float r, float x, float y) {
        this->r = r;
        this->x = x;
        this->y = y;
    }

    void set_circle(float r, float x, float y) {
        this->r = r;
        this->x = x;
        this->y = y;
    }

    float square() {
        return M_PI * r * r;
    }

    bool triangle_around_new_metod(Triangle &t) {
        double p = (t.get_a() + t.get_b() + t.get_c()) / 2;
        double S = sqrt(p * (p - t.get_a()) * (p - t.get_b()) * (p - t.get_c()));
        double R = (t.get_a() * t.get_b() * t.get_c()) / (4 * S);
        return abs(R - r) < 1e-6;
    }

    bool triangle_in_new_metod(Triangle &t) {
        double p = (t.get_a() + t.get_b() + t.get_c()) / 2;
        double S = sqrt(p * (p - t.get_a()) * (p - t.get_b()) * (p - t.get_c()));
        double r_in = S / p;
        return abs(r_in - r) < 1e-6;
    }

    // bool triangle_around(Triangle &t) {
    //     double max_side = max({t.get_a(), t.get_b(), t.get_c()});
    //     if (r >= ((max_side * sqrt(3))/3)) {
    //         return true;
    //     }
    //     else {
    //         return false;
    //     }
    // }
    // bool triangle_in(Triangle &t) {
    //     double max_side = min({t.get_a(), t.get_b(), t.get_c()});
    //     if (r <= ((max_side * sqrt(3))/6)) {
    //         return true;
    //     }
    //     else {
    //         return false;
    //     }
    // }
    bool check_circle(Circle &c){
        double d = sqrt(pow(c.x - x, 2) + pow(c.y - y, 2));
        return (abs(r - c.r) <= d) && (d <= r + c.r);
    }
};

int main() {
    Triangle triangle(3, 4, 5), triangle2(6, 8, 10);
    triangle.show();
    triangle2.show();
    cout<<triangle.is_similar(triangle2);
    return 0;
}