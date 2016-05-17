// Class_Point.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Point.h"


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Rus");

	Point A;
	A.Show();
	Point B(2, 2, 'B');
	B.Show();

	system("pause");
    return 0;
}