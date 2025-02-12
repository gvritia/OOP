#include <cmath>
#include <iostream>
#include <math.h>

using namespace std;

class ComplexNumber {
private:
    double re, im;
    double module, angle;

public:
    ComplexNumber(double re, double im) {
        this->re = re;
        this->im = im;
        module = sqrt(re*re + im*im);
        angle = atan2(im, re);
    }
    void set(double re1, double im1) {
        re = re1;
        im = im1;
        module = sqrt(re * re + im * im);
        angle = atan(im/re);
    }
    void show() {
        cout <<"Number = " << re << " + " << im << " * i" << endl;
        cout <<"Module = " << module << ", angle = " << angle << endl;
    }
};

int main() {
    ComplexNumber number1(3, 4), number2(3, 5);
    number1.show();
    cout<< "---------------------"<< endl;
    number1.set(5, 6);
    number1.show();
    cout<< "---------------------"<< endl;
    number2.show();
    number2.set(8, 12);
    cout<< "---------------------"<< endl;
    number2.show();
    return 0;
}