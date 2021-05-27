#include <iostream>
using namespace std;

class Rational {
public:
    Rational() {
        num = 0;
        den = 1;
        nod = 1;
    }

    Rational(int numerator, int denominator) {
        num = numerator;
        den = denominator;
        int a = num;
        int b = den;
        if (a < 0) a = abs(a);
        if (b < 0) b = abs(b);
        while (a > 0 && b > 0) {
            if (a > b) {
                a %= b;
            } else {
                b %= a;
            }
        }
        nod = a+b;
        if (den < 0){
            den = abs(den);
            num = -num;
        }
        Numerator();
        Denominator();
    }

    int Numerator() const {
        if (num % nod != 0 || nod == 1 || num == 0){
            return num;
        } else {
            return num/nod;
        }
    }

    int Denominator() const {
        if (den % nod != 0 || nod == 1 || den == 1){
            return den;
        } else {
            return den/nod;
        }

    }

private:
    int nod;
    int num;
    int den;
};

bool operator== (Rational lh, Rational rh){
    if (lh.Numerator() == rh.Numerator() && lh.Denominator() == rh.Denominator()){
        return true;
    } else {
        return false;
    }
}

Rational operator+ (Rational lhs, Rational rhs){
    int a = (lhs.Numerator() * rhs.Denominator()) + (rhs.Numerator() * lhs.Denominator());
    int b = lhs.Denominator() * rhs.Denominator();
    return (Rational (a, b));
}

Rational operator- (Rational lhs, Rational rhs){
    int a = lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator();
    int b = lhs.Denominator() * rhs.Denominator();
    return (Rational (a, b));
}

Rational operator* (Rational lhs, Rational rhs){
    return Rational((lhs.Numerator() * rhs.Numerator()), (lhs.Denominator()*rhs.Denominator()));
}

Rational operator/ (Rational lhs, Rational rhs){
    return Rational(lhs.Numerator() * rhs.Denominator(), lhs.Denominator()*rhs.Numerator());
}

