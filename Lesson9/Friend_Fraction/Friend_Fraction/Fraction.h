#pragma once
class Fraction
{
	int n;
	int d;
public:
	Fraction(int numerator = 0, int denominator = 0);

	int GetNumerator() const;
	int GetDenominator() const;

	friend Fraction operator+(const Fraction& lval, const Fraction& rval);

	friend istream& operator>>(istream& in, Fraction& obj);
	friend ostream& operator<<(ostream& out, Fraction& obj);

	void Show() const;

	~Fraction();
};

