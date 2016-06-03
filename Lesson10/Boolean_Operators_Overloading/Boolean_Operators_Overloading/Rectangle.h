#pragma once
#include "Point.h"

class Rectangle
{
	Point leftTop;
	Point rightBottom;
public:
	Rectangle() {}


	Rectangle(double x1, double y1, double x2, double y2) :
		leftTop(Point(x1, y1)),
		rightBottom(Point(x2, y2)) {}

	double Square() const
	{
		return abs(leftTop.x - rightBottom.x) * abs(leftTop.y - rightBottom.y);
	}

	bool operator>(const Rectangle& rval) const
	{
		return Square() > rval.Square();
	}

	friend ostream& operator<<(ostream& out, const Rectangle& obj);
	friend istream& operator>>(istream& in, Rectangle& obj);
};
