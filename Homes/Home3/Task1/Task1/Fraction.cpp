#include "stdafx.h"
#include "Fraction.h"


int Fraction::LCD(int left, int right) {
	int lcd = left > right ? left : right;
	while (lcd % left || lcd % right)
		++lcd;
	return lcd;
}


int Fraction::GCD(int left, int right) {
	int tmp;
	while (right) {
		tmp = right;
		right = left % right;
		left = tmp;
	}
	return left;
}


void Fraction::Reduce() {
	int gcd = GCD(numerator, denominator);
	numerator = numerator / gcd;
	denominator = denominator / gcd;
	if (denominator < 0) {
		numerator = -numerator;
		denominator = -denominator;
	}
}


Fraction::Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {
	Reduce();
}


void Fraction::Add(const Fraction& f) {
	int lcd = LCD(denominator, f.denominator);
	numerator = numerator * lcd / denominator;
	numerator += f.numerator * lcd / f.denominator;
	denominator = lcd;
	Reduce();
}


void Fraction::Add(int numerator, int denominator) {
	Fraction f(numerator, denominator);
	Add(f);
}


Fraction Fraction::operator+(const Fraction& rval) const {
	Fraction tmp(*this);
	tmp.Add(rval);
	return tmp;
}


void Fraction::Sub(const Fraction& f) {
	int lcd = LCD(denominator, f.denominator);
	numerator = numerator * lcd / denominator;
	numerator -= f.numerator * lcd / f.denominator;
	denominator = lcd;
	Reduce();
}


void Fraction::Sub(int numerator, int denominator) {
	Fraction f(numerator, denominator);
	Sub(f);
}


Fraction Fraction::operator-(const Fraction& rval) const {
	Fraction tmp(*this);
	tmp.Sub(rval);
	return tmp;
}


void Fraction::Mult(const Fraction& f) {
	numerator *= f.numerator;
	denominator *= f.denominator;
	Reduce();
}


void Fraction::Mult(int numerator, int denominator) {
	Fraction f(numerator, denominator);
	Mult(f);
}


Fraction Fraction::operator*(const Fraction& rval) const {
	Fraction tmp(*this);
	tmp.Mult(rval);
	return tmp;
}


void Fraction::Div(const Fraction& f) {
	numerator *= f.denominator;
	denominator *= f.numerator;
	Reduce();
}


void Fraction::Div(int numerator, int denominator) {
	Fraction f(numerator, denominator);
	Div(f);
}


Fraction Fraction::operator/(const Fraction& rval) const {
	Fraction tmp(*this);
	tmp.Div(rval);
	return tmp;
}


void Fraction::Show() const {
	if (numerator) {
		int integer = numerator / denominator;
		int remainder = numerator % denominator;
		if (integer) {
			std::cout << integer;
			if (remainder)
				std::cout << "+";
		}
		if (remainder){
			std::cout << integer ? std::cout << abs(remainder) : std::cout << remainder;
			std::cout << "/" << denominator;
		}
	}
	else
		std::cout << numerator;
	std::cout << std::endl;
}


Fraction::~Fraction() {}


Fraction pow(const Fraction& base, double exponent) {
	return Fraction(pow(base.numerator, exponent), pow(base.denominator, exponent));
}


Fraction abs(const Fraction& obj) {
	return Fraction(abs(obj.numerator), abs(obj.denominator));
}


std::ostream& operator<<(std::ostream& os, const Fraction& obj) {
	if (obj.numerator) {
		int integer = obj.numerator / obj.denominator;
		int remainder = obj.numerator % obj.denominator;
		if (integer) {
			os << integer;
			if (remainder)
				os << "+";
		}
		if (remainder){
			integer ? os << abs(remainder) : os << remainder;
			os << "/" << obj.denominator;
		}
	}
	else
		os << obj.numerator;
	return os;
}


std::istream& operator>>(std::istream& is, Fraction& obj) {
	return is >> obj.numerator >> obj.denominator;
}
