#include "stdafx.h"
#include "Point.h"

Point::Point()
{
	cout << "������� ���������� �����: ";
	cin >> x >> y;
	cout << "������� ��� �����: ";
	cin >> name;
}

//Point::Point(int x, int y, char name)
//{
//	this->x = x;
//	this->y = y;
//	this->name = name;
//}

void Point::Show() const
{
	cout << name << "(" << x << ", " << y << ")" << endl;
}

Point::~Point()
{
}
