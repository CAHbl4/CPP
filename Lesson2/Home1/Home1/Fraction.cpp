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
	cout << "¬ведите числитель и знаменатель";
	cin >> numerator >> denominator;
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

void Fraction::Mult(Fraction f) {
	this->numerator *= f.numerator;
	this->denominator *= f.denominator;
	this->Reduce();
}

void Fraction::Mult(int numerator, int denominator) {
	Fraction f(numerator, denominator);
	this->Mult(f);
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

void Fraction::Show() {
	if (numerator) {
		int integer = numerator / denominator;
		int remainder = numerator % denominator;
		if (integer) {
			cout << integer;
			if (remainder)
				cout << "+";
		}
		if (remainder)
			cout << remainder << "/" << denominator;
	}
	else
		cout << numerator;
	cout << endl;
}

Fraction::~Fraction()
{
}
