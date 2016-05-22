//#include "rational.h"
#include <iostream>

using namespace std;

class Rational {
private:
	int nominator;
	int denominator;
public:

	Rational() : nominator(0), denominator(0) { }
	Rational(const Rational& rhs) : nominator(rhs.nominator),denominator(rhs.denominator){ normalize(); }
	Rational(int x) : nominator(x), denominator(1) {}
	int getNominator()const;
	int getDenominator()const;
	void setNominator(int newNominator);
	void setDenominator(int newDenominator);
	Rational operator+=(const Rational& rhs);
	Rational& operator++();
	Rational operator++(int);
	void normalize();
};

int Rational::getDenominator()const {
	return denominator;
}
int Rational::getNominator()const {
	return nominator;
}
void Rational::setNominator(int newNominator) {
	nominator = newNominator;
}
void Rational::setDenominator(int newDenominator) {
	denominator = newDenominator;
}
int greatestCommonDivisor(int x, int y) {
	while (y != 0) {
		int temp = x % y;
		x = y;
		y = temp;
	}
	return x;
}
void Rational::normalize() {
	if (nominator < 0 && denominator < 0) {
		nominator *= -1;
		denominator *= -1;
	}
	else if (nominator > 0 && denominator < 0) {
		nominator *= -1;
		denominator *= -1;
	}
	int gcd=greatestCommonDivisor(nominator, denominator);
	nominator /= gcd;
	denominator /= gcd;

}

Rational Rational::operator+=(const Rational& rhs) {
	int newDenominator;
	int newNominator;
	Rational newNum;
	newDenominator = denominator*rhs.denominator;
	newNominator = nominator+=rhs.nominator;
	newNum.nominator = newNominator;
	newNum.denominator = newDenominator;
	return newNum;
}
Rational operator+(const Rational& lhs, const Rational& rhs) {
	int newDenominator = lhs.getDenominator()*rhs.getDenominator();
	int tempLhs = lhs.getNominator()*rhs.getDenominator();
	int tempRhs = rhs.getNominator()*lhs.getDenominator();
	int newNominator = tempLhs + tempRhs;
	Rational newNum;
	newNum.setDenominator(newDenominator);
	newNum.setNominator(newNominator);
	return newNum;
}
Rational& Rational::operator++() {//pre increment
	nominator += denominator;
	return *this;
}

Rational Rational::operator++(int i) {//post increment
	Rational temp;
	temp.setNominator(nominator);
	temp.setDenominator(denominator);
	nominator += denominator;
	
	return (temp);
}

ostream& operator<<(ostream& os, Rational& rn) {
	cout << rn.getNominator() << "/" << rn.getDenominator();
	return os;
}
istream& operator>>(istream& is, Rational& rhs) {
	char uselessChar;
	int tempNom;
	int tempDenom;
	is >> tempNom >> uselessChar >> tempDenom;
	rhs.setNominator(tempNom);
	rhs.setDenominator(tempDenom);
	rhs.normalize();
	return is;
}

Rational& operator--(Rational& lhs) {//predecrement
	int tempDenom;
	int tempNom;

	tempNom=lhs.getNominator();
	tempDenom=lhs.getDenominator();
	tempNom -= tempDenom;
	lhs.setNominator(tempNom);
	lhs.setDenominator(tempDenom);
	return lhs;
}

Rational& operator--(Rational& lhs,int i){//postdecrement
	int tempDenom;
	int tempNom;
	Rational temp;
	temp.setNominator(lhs.getNominator());
	temp.setDenominator(lhs.getDenominator());
	tempNom = lhs.getNominator();
	tempDenom = lhs.getDenominator();
	tempNom -= tempDenom;
	lhs.setNominator(tempNom);
	lhs.setDenominator(tempDenom);
	return lhs;
}
bool operator!=(const Rational& lhs, const Rational& rhs) {
	if (lhs.getDenominator() == rhs.getDenominator() && lhs.getNominator() == rhs.getDenominator()) {
		return false;
	}
	else return true;
}
bool operator==(const Rational& lhs, const Rational& rhs) {
	if (lhs.getDenominator() == rhs.getDenominator() && lhs.getNominator() == rhs.getDenominator()) {
		return true;
	}
	else return false;
}


int main() {
	Rational a, b;
	cout << "Input two rational numbers.\n";
	cout << "a: ";
	cin >> a;
	cout << "b: ";
	cin >> b;
	Rational one = 1;

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "one = " << one << endl;
	cout << "a += b: " << (a += b) << endl;	// Implement as member
	cout << "a = " << a << endl;
	cout << "a + one: " << (a + one) << endl;	// Implement as non-member, but not a friend
	cout << "a == one: " << boolalpha << (a == one) << endl;
	cout << "1 == one: " << boolalpha << (1 == one) << endl;  // How does this work?
	cout << "a != one: " << boolalpha << (a != one) << endl;  // Do not implement as friend.

	cout << "a = " << a << endl;
	cout << "++a = " << (++a) << endl;
	cout << "a = " << a << endl;
	cout << "a++ = " << (a++) << endl;
	cout << "a = " << a << endl;
	cout << "--a = " << (--a) << endl;
	cout << "a = " << a << endl;
	cout << "a-- = " << (a--) << endl;
	cout << "a = " << a << endl;
}