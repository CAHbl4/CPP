// stdafx.cpp: исходный файл, содержащий только стандартные включаемые модули
// Friend_Fraction.pch будет предкомпилированным заголовком
// stdafx.obj будет содержать предварительно откомпилированные сведения о типе

#include "stdafx.h"


// TODO: Установите ссылки на любые требующиеся дополнительные заголовки в файле STDAFX.H
// , а не в данном файле

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
