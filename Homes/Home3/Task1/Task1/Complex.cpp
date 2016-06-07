#include "stdafx.h"
#include "Complex.h"


Complex::Complex(float x, float y): x(x), y(y) {}


Complex Complex::operator+(const Complex& rval) const {
	Complex tmp;
	tmp.x = this->x + rval.x;
	tmp.y = this->y + rval.y;
	return tmp;
}


Complex Complex::operator-(const Complex& rval) const {
	Complex tmp;
	tmp.x = this->x - rval.x;
	tmp.y = this->y - rval.y;
	return tmp;
}


Complex Complex::operator*(const Complex& rval) const {
	Complex tmp;
	int x1 = this->x, y1 = this->y, x2 = rval.x, y2 = rval.y;
	tmp.x = x1 * x2 - y1 * y2;
	tmp.y = x1 * y2 - y1 * x2;
	return tmp;
}


Complex Complex::operator/(const Complex& rval) const {
	Complex tmp;
	int x1 = this->x, y1 = this->y, x2 = rval.x, y2 = rval.y;
	tmp.x = (x1 * x2 + y1* y2) / (pow(x2, 2) + pow(y2, 2));
	tmp.y = (x2 * y1 - x1 * y2) / (pow(x2, 2) + pow(y2, 2));
	return tmp;
}


Complex::~Complex() {}
