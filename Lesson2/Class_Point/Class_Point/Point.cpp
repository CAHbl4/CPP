#include "stdafx.h"
#include "Point.h"

Point::Point()
{
	cout << "¬ведите координаты точки: ";
	cin >> x >> y;
	cout << "¬ведите им€ точки: ";
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
