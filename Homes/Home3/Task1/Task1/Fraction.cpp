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
	while(right) {
		tmp = right;
		right = left % right;
		left = tmp;
	}
	return left;
}

void Fraction::Reduce() {
	int gcd = GCD(this->numerator, this->denominator);
	this->numerator = this->numerator / gcd;
	this->denominator = this->denominator / gcd;
}

Fraction::Fraction()
{
	std::cout << "Введите числитель и знаменатель";
	std::cin >> numerator >> denominator;
}

void Fraction::Add(Fraction f) {
	int lcd = LCD(this->denominator, f.denominator);
	this->numerator = this->numerator * lcd / this->denominator;
	this->numerator += f.numerator * lcd / f.denominator;
	this->denominator = lcd;
	this->Reduce();
}

void Fraction::Add(int numerator, int denominator) {
	Fraction f(numerator, denominator);
	this->Add(f);
}


Fraction Fraction::operator+(const Fraction& rval) const {
	Fraction tmp(*this);
	tmp.Add(rval);
	return tmp;
}





void Fraction::Sub(Fraction f) {
	int lcd = LCD(this->denominator, f.denominator);
	this->numerator = this->numerator * lcd / this->denominator;
	this->numerator -= f.numerator * lcd / f.denominator;
	this->denominator = lcd;
	this->Reduce();
}

void Fraction::Sub(int numerator, int denominator) {
	Fraction f(numerator, denominator);
	this->Sub(f);
}

Fraction Fraction::operator-(const Fraction& rval) const {
	Fraction tmp(*this);
	tmp.Sub(rval);
	return tmp;
}

void Fraction::Mult(Fraction f) {
	this->numerator *= f.numerator;
	this->denominator *= f.denominator;
	this->Reduce();
}

void Fraction::Mult(int numerator, int denominator) {
	Fraction f(numerator, denominator);
	this->Mult(f);
}

Fraction Fraction::operator*(const Fraction& rval) const {
	Fraction tmp(*this);
	tmp.Mult(rval);
	return tmp;
}


void Fraction::Div(Fraction f) {
	this->numerator *= f.denominator;
	this->denominator *= f.numerator;
	this->Reduce();
}

void Fraction::Div(int numerator, int denominator) {
	Fraction f(numerator, denominator);
	this->Div(f);
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
		if (remainder)
			std::cout << remainder << "/" << denominator;
	}
	else
		std::cout << numerator;
	std::cout << std::endl;
}

Fraction::~Fraction()
{
}
