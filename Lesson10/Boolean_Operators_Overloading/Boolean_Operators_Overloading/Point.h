#pragma once

class Circle;
class Rectangle;

class Point
{
	double x, y;
	friend Circle;
	friend Rectangle;
public:
	Point(double x = .0, double y = .0) : x(x), y(y) {}

	void Set();

	void Show() const;
	~Point();
};
