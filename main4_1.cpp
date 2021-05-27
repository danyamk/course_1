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

int main() {
    {
        const Rational r(3, 10);
        if (r.Numerator() != 3 || r.Denominator() != 10) {
            cout << "Rational(3, 10) != 3/10" << endl;

        }
    }

    {
        const Rational r(8, 12);
        if (r.Numerator() != 2 || r.Denominator() != 3) {
            cout << "Rational(8, 12) != 2/3" << endl;

        }
    }

    {
        const Rational r(-4, 6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(-4, 6) != -2/3" << endl;

        }
    }

    {
        const Rational r(4, -6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(4, -6) != -2/3" << endl;

        }
    }

    {
        const Rational r(0, 15);
        if (r.Numerator() != 0 || r.Denominator() != 1) {
            cout << "Rational(0, 15) != 0/1" << endl;

        }
    }

    {
        const Rational defaultConstructed;
        if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
            cout << "Rational() != 0/1" << endl;

        }
    }

    cout << "OK" << endl;
    return 0;
}
