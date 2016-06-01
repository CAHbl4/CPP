// stdafx.cpp: �������� ����, ���������� ������ ����������� ���������� ������
// Friend_Fraction.pch ����� ������������������� ����������
// stdafx.obj ����� ��������� �������������� ����������������� �������� � ����

#include "stdafx.h"


// TODO: ���������� ������ �� ����� ����������� �������������� ��������� � ����� STDAFX.H
// , � �� � ������ �����

//Fraction operator+(const Fraction& lval, const Fraction& rval)
//{
//	int numerator = lval.GetNumerator() * rval.GetDenominator() + lval.GetDenominator() * rval.GetNumerator();
//	int denominator = lval.GetNumerator() * rval.GetNumerator();
//	return Fraction(numerator, denominator);
//}

Fraction operator+(const Fraction& lval, const Fraction& rval)
{
	int numerator = lval.n * rval.d + lval.d * rval.n;
	int denominator = lval.n * rval.d;
	return Fraction(numerator, denominator);
}


istream& operator>>(istream& in, Fraction& obj)
{
	cout << "Enter numerator: ";
	in >> obj.n;
	cout << "Enter denominator: ";
	in >> obj.d;
	return in;
}


ostream& operator<<(ostream& out, Fraction& obj)
{
	(obj.n > obj.d) ? out << obj.n / obj.d << " " << obj.n % obj.d << "/" << obj.d : out << obj.n << "/" << obj.d;
	out << endl;
	return out;
}
