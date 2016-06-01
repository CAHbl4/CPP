#pragma once

class Triangle;

class Point
{
	int x, y;

	friend Triangle;

public:
	Point(int x = 0, int y = 0);

	friend istream& operator>>(istream& in, Point& obj);
	friend ostream& operator<<(ostream& out, const Point& obj);

};
