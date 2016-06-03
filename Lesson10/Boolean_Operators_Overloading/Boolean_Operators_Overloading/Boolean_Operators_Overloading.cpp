// Boolean_Operators_Overloading.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Circle.h"
#include "Rectangle.h"


int _tmain(int argc, _TCHAR* argv[])
{
	//Circle c1;
	//cout << c1;

	//c1.Set();
	//cout << c1;

	//Circle c2;
	//c2.Set();
	//cout << c2;

	//(c1 > c2) ? cout << "c1 > c2" : cout << "c1 <= c2";
	//cout << endl;

	Rectangle r1;
	cin >> r1;
	cout << r1;

	Rectangle r2(2, 2, 7, -3);
	cout << r2;

	(r1 > r2) ? cout << "r1 > r2" : cout << "r1 <= r2";
	cout << endl;

	system("pause");
	return 0;
}
