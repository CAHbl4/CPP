#pragma once
#include "Point.h"

class Triangle
{
	Point A, B, C;
public:
	void SetVertices();
	void ShowVertices() const;
};
