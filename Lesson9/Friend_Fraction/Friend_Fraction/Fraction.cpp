#include "stdafx.h"
#include "Fraction.h"


Fraction::Fraction(int numerator, int denominator) : n(numerator), d(denominator)
{
}


int Fraction::GetNumerator() const
{
	return n;
}


int Fraction::GetDenominator() const
{
	return d;
}


void Fraction::Show() const
{
	(n > d) ? cout << n / d << " " << n % d << "/" << d : cout << n << "/" << d;
	cout << endl;
}


Fraction::~Fraction()
{
}
