#include "stdafx.h"
#include "Point.h"

void Point::Show()
{
	cout << "Point(" << x << "," << y << ")\n";
}

void Point::CopyData(const Point& other)
{
	if (this == &other)
		return;
	x = other.x;
	y = other.y;
}

void Point::SetData(float x, float y)
{
	this->x = x;
	this->y = y;
}

void Point::InputData()
{
	cout << "Input X, Y: ";
	cin >> x >> y;
}
