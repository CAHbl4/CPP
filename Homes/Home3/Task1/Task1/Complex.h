#pragma once
class Complex
{
	float x;
	float y;
public:
	Complex(float x = .0, float y = .0);

	Complex operator+(const Complex& rval) const;
	Complex operator-(const Complex& rval) const;
	Complex operator*(const Complex& rval) const;
	Complex operator/(const Complex& rval) const;

	~Complex();
};

