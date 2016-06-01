// stdafx.cpp: исходный файл, содержащий только стандартные включаемые модули
// Friend_Class.pch будет предкомпилированным заголовком
// stdafx.obj будет содержать предварительно откомпилированные сведения о типе

#include "stdafx.h"

// TODO: Установите ссылки на любые требующиеся дополнительные заголовки в файле STDAFX.H
// , а не в данном файле

istream& operator>>(istream& in, Point& obj)
{
	cout << "Enter coordinates of point: ";
	cin >> obj.x >> obj.y;
	return in;
}


ostream& operator<<(ostream& out, const Point& obj)
{
	out << "Point(" << obj.x << ", " << obj.y << ")\n";
	return out;
}