// Даны две рациональные дроби: a/b и c/d. Сложить их и результат представьте в виде несократимой дроби m/n. Вывести числа m и n.
// a, b, c, d ≤ 1000.

#include <iostream>

using namespace std;

class fraction {
	//a / b - дробь
	int a;
	int b;

	int gcd (int a, int b) {
		//евклид
    	return (b == 0) ? abs(a) : this->gcd(b, a % b);
	}

public:
	bool simplification(){
		int gcd = this->gcd(this->a, this->b);
		if (gcd == 1) {
			return 0;
		} else {
			this->a /= gcd;
			this->b /= gcd;
			return 1;
		}
	}

	fraction(int a, int b) : a(a), b(b){
		//упрощение
		this->simplification();
	}

	fraction(const fraction& other){}

	fraction operator+(const fraction& other){
		int a = this->a * other.b + other.a * this->b;
		int b = this->b * other.b;
		return fraction(a, b);
	}

	fraction& operator=(const fraction&& other){
		if (this != &other) {
			this->a = other.a;
			this->b = other.b;
			this->simplification();
		}
		return *this;
	}

	friend ostream& operator<<(ostream& os, const fraction& other){
		os << other.a << " " << other.b;
		return os;
	}
};

int main(){
	int a = 0, b = 0, c = 0, d = 0;
	cin >> a;
	cin >> b;
	cin >> c;
	cin >> d;
	fraction aa(a, b);
	fraction bb(c, d);

	cout << aa + bb << endl;
	return 0;
}