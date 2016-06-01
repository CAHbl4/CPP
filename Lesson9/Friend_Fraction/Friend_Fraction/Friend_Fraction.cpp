// Friend_Fraction.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	Fraction f1(2, 3);
	f1.Show();
	Fraction f2(8, 3);
	f2.Show();
	Fraction f3;
	f3 = f1 + f2;
	f3.Show();
	
	cin >> f1;
	cout << f1;

	system("pause");
	return 0;
}

