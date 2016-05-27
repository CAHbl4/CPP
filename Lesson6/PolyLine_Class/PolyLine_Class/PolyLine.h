#pragma once
#include "stdafx.h"
#include "Point.h"

class PolyLine
{
	int size;
	Point *ptr;
public:

	PolyLine() : size(0), ptr(NULL)
	{
		cout << "Default constructor PolyLine\n";
	}

	PolyLine(int size) : size(size)
	{
		cout << "Parameter constructor PolyLine\n";
		ptr = new Point[size];
	}

	PolyLine(const PolyLine& other);

	void Add(int size);
	
	void SetData();

	void Show();

	~PolyLine();
};
