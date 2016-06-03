#include "stdafx.h"
#include "Circle.h"


void Circle::Set()
{
	cout << "Enter centre's coordinates: ";
	cin >> centre.x >> centre.y;
	cout << "Enter radius: ";
	cin >> radius;
}


Circle::~Circle() {}


ostream& operator<<(ostream& out, const Circle& obj)
{
	out << "Circle:\n" << "Centre: ";
	obj.centre.Show();
	out << "Radius: " << obj.radius << endl;
	return out;
}
