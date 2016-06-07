#pragma once
class Fraction
{
	//числитель
	int numerator;

	//Знаменатель
	int denominator;

	//Наименьший общий знаменатель
	static int LCD(int left, int right);

	//Наибольший общий делитель
	static int GCD(int left, int right);

	//Сократить дробь
	void Reduce();

public:
	Fraction();
	Fraction(int numerator, int denominator)
		: numerator(numerator),
		  denominator(denominator) {}

	//Сложение
	void Add(Fraction f);
	void Add(int numerator, int denominator);
	Fraction operator+(const Fraction& rval) const;

	//Вычитание
	void Sub(Fraction f);
	void Sub(int numerator, int denominator);
	Fraction operator-(const Fraction& rval) const;

	//Умножение
	void Mult(Fraction f);
	void Mult(int numerator, int denominator);
	Fraction operator*(const Fraction& rval) const;

	//Деление
	void Div(Fraction f);
	void Div(int numerator, int denominator);
	Fraction operator/(const Fraction& rval) const;

	void Show() const;

	~Fraction();
};

