#include <iostream>
#include <sstream>
#include <map>
using namespace std;

class Rational {
public:
    Rational() {
        num = 0;
        den = 1;
        nod = 1;
    }

    Rational(int numerator, int denominator) {
        if (denominator == 0) throw invalid_argument("Invalid argument");
        num = numerator; den = denominator;
        int a = num, b = den;
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
    int a = (lhs.Numerator() * rhs.Denominator()) - (rhs.Numerator() * lhs.Denominator());
    int b = lhs.Denominator() * rhs.Denominator();
    return (Rational (a, b));
}

Rational operator* (Rational lhs, Rational rhs){
    return Rational(lhs.Numerator() * rhs.Numerator(), lhs.Denominator()*rhs.Denominator());
}

Rational operator/ (Rational lhs, Rational rhs){
    if (rhs.Numerator() ==0){
        throw domain_error("Division by zero");
    } else return Rational((lhs.Numerator() * rhs.Denominator()), (lhs.Denominator()*rhs.Numerator()));
}

bool operator < (Rational lhs, Rational rhs){
    return ((double)lhs.Numerator() / (double)lhs.Denominator() < (double)rhs.Numerator() / (double)rhs.Denominator());
}

ostream& operator << (ostream& stream, const Rational& a){
    stream << a.Numerator() << "/" << a.Denominator();
    return stream;
}

istream& operator >> (istream& stream, Rational& a){
    int d, c;
    if (stream >> d && stream.ignore(1) && stream >> c){
        a = {d ,c};
    }
    return stream;
}

int main (){
    try {
        Rational r1, r2;
        char oper;
        cin >> r1;
        cin >> oper;
        cin >> r2;
        switch (oper) {
            case '+' :
                cout << r1 + r2;
                break;
            case '-' :
                cout << r1 - r2;
                break;
            case '*' :
                cout << r1 * r2;
                break;
            case '/' :
                cout << r1 / r2;
                break;
        }
    } catch(invalid_argument& e) {
        cout << e.what() << endl;
    } catch (domain_error& k){
        cout << k.what() << endl;
    }
}