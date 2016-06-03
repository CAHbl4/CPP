#include "stdafx.h"
#include "Point.h"


void Point::Set()
{
	cout << "Enter coordinates: ";
	cin >> x >> y;
}


void Point::Show() const
{
	cout << "Point(" << x << "," << y << ")\n";
}


Point::~Point() {}
