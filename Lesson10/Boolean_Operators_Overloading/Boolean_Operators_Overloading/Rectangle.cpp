#include "stdafx.h"
#include "Rectangle.h"


ostream& operator<<(ostream& out, const Rectangle& obj) {
	out << "Rectangle:\n" << "LeftTop: ";
	obj.leftTop.Show();
	out << "RightBottom: ";
	obj.rightBottom.Show();
	out << "Square: " << obj.Square() << endl;
	return out;
}


istream& operator>>(istream& in, Rectangle& obj) {
	cout << "Enter leftTop:\n";
	obj.leftTop.Set();
	cout << "Enter rightBottom:\n";
	obj.rightBottom.Set();
	return in;
}
