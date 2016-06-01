#include "stdafx.h"
#include "Triangle.h"


void Triangle::SetVertices()
{
	cin >> A >> B >> C;
}


void Triangle::ShowVertices() const
{
	cout << "A:(" << A.x << "," << A.y << ")\n";
	cout << "B:(" << B.x << "," << B.y << ")\n";
	cout << "C:(" << C.x << "," << C.y << ")\n";
}
