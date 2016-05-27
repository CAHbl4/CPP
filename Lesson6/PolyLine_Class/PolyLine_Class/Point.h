#pragma once
#include "stdafx.h"

class Point
{
	float x, y;
public:
	Point(float x = .0, float y = .0) : x(x), y(y)
	{
		cout << "Default constructor Point\n";
	}

	Point(const Point& other): x(other.x), y(other.y)
	{
		cout << "Copy constructor Point\n";
	}

	void Show();

	void CopyData(const Point& other);

	void SetData(float x, float y);

	void InputData();


	~Point()
	{
		cout << "Destructor Point\n";
	}

};
