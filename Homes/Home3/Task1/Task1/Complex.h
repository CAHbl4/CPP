#pragma once
#include "Fraction.h"

class Complex
{
	Fraction x;
	Fraction y;
public:
	Complex(Fraction x = 0, Fraction y = 0);

	Complex operator+(const Complex& rval) const;
	Complex operator-(const Complex& rval) const;
	Complex operator*(const Complex& rval) const;
	Complex operator/(const Complex& rval) const;

	friend std::ostream& operator<<(std::ostream& os, const Complex& obj);
	friend std::istream& operator>>(std::istream& is, Complex& obj);

	~Complex();
};

