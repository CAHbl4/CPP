#pragma once
class Fraction
{
	//���������
	int numerator;

	//�����������
	int denominator;

	//���������� ����� �����������
	static int LCD(int left, int right);

	//���������� ����� ��������
	static int GCD(int left, int right);

	//��������� �����
	void Reduce();

public:
	Fraction();
	Fraction(int numerator, int denominator)
		: numerator(numerator),
		  denominator(denominator) {}

	//��������
	void Add(Fraction f);
	void Add(int numerator, int denominator);

	//���������
	void Sub(Fraction f);
	void Sub(int numerator, int denominator);

	//���������
	void Mult(Fraction f);
	void Mult(int numerator, int denominator);

	//�������
	void Div(Fraction f);
	void Div(int numerator, int denominator);

	void Show();

	~Fraction();
};

