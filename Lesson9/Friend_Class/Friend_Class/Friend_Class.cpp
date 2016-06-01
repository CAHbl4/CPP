// Friend_Class.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	Point p1(2, 2);
	cout << p1;
	cin >> p1;
	cout << p1;

	Triangle tr1;
	tr1.SetVertices();
	tr1.ShowVertices();

	system("pause");
	return 0;
}

