// Даны две рациональные дроби: a/b и c/d. Сложить их и результат представьте в
// виде несократимой дроби m/n. Вывести числа m и n.
// a, b, c, d ≤ 1000.

#include <iostream>

using namespace std;

class fraction {
    // a / b - дробь
    int a;
    int b;

    static int gcd(int a, int b) {
        //евклид
        return (b == 0) ? abs(a) : gcd(b, a % b);
    }

   public:
    bool simplification() {
        int gcd = fraction::gcd(a, b);
        if (gcd == 1) {
            return 0;
        } else {
            a /= gcd;
            b /= gcd;
            return 1;
        }
    }

    fraction(int a, int b) : a(a), b(b) {
        //упрощение
        simplification();
    }

    fraction(const fraction& other) {}

    fraction operator+(const fraction& other) {
        int a_new = a * other.b + other.a * b;
        int b_new = b * other.b;
        return fraction(a_new, b_new);
    }

    fraction& operator=(const fraction&& other) {
        if (this != &other) {
            a = other.a;
            b = other.b;
            simplification();
        }
        return *this;
    }

    friend ostream& operator<<(ostream& os, const fraction& other) {
        os << other.a << " " << other.b;
        return os;
    }
};

int main() {
    int a = 0, b = 0, c = 0, d = 0;
    cin >> a >> b >> c >> d;

    fraction fr1(a, b);
    fraction fr2(c, d);

    cout << fr1 + fr2 << endl;

    return 0;
}