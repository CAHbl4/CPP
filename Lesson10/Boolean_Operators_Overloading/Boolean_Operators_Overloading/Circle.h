#pragma once
#include "Point.h"

class Circle
{
	Point centre;
	double radius;
public:
	Circle() : radius(0) {}


	void Set();

	friend ostream& operator<<(ostream& out, const Circle& obj);


	bool operator>(const Circle& rval) const
	{
		return radius > rval.radius;
	}


	bool operator==(const Circle& rval) const
	{
		return radius == rval.radius;
	}


	bool operator<(const Circle& rval) const
	{
		return radius < rval.radius;
	}


	bool operator!=(const Circle& rval) const
	{
		return radius != rval.radius;
	}


	~Circle();
};
