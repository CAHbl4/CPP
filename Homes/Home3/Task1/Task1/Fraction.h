#pragma once
class Fraction {
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
	Fraction(int numerator = 0, int denominator = 1);

	//Сложение
	void Add(const Fraction& f);
	void Add(int numerator, int denominator);
	Fraction operator+(const Fraction& rval) const;

	//Вычитание
	void Sub(const Fraction& f);
	void Sub(int numerator, int denominator);
	Fraction operator-(const Fraction& rval) const;


	//Умножение
	void Mult(const Fraction& f);
	void Mult(int numerator, int denominator);
	Fraction operator*(const Fraction& rval) const;

	//Деление
	void Div(const Fraction& f);
	void Div(int numerator, int denominator);
	Fraction operator/(const Fraction& rval) const;

	friend Fraction pow(const Fraction& base, double exponent);
	friend Fraction abs(const Fraction& base);

	void Show() const;

	friend std::ostream& operator<<(std::ostream& os, const Fraction& obj);
	friend std::istream& operator>>(std::istream& os, Fraction& obj);


	friend bool operator<(const Fraction& lhs, const Fraction& rhs) {
		return lhs.numerator * rhs.denominator < rhs.numerator * lhs.denominator;
	}


	friend bool operator<=(const Fraction& lhs, const Fraction& rhs) {
		return !(rhs < lhs);
	}


	friend bool operator>(const Fraction& lhs, const Fraction& rhs) {
		return rhs < lhs;
	}


	friend bool operator>=(const Fraction& lhs, const Fraction& rhs) {
		return !(lhs < rhs);
	}


	~Fraction();
};
