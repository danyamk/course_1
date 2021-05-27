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
        if (b < 0) b = abs(b);
        if (a < 0) a = abs(a);
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


int main() {
    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
        }
    }

    {
        Rational a(-5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        cout << c.Numerator() << " " << c.Denominator() << endl;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
        }
    }

    cout << "OK" << endl;
    return 0;
}