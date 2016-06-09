// Task1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Complex.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	Complex c1(8, 1);
	cout << c1 << endl;

	Complex c2(2, -3);
	cout << c2 << endl;

	cout << c1 + c2 << endl;
	cout << c1 - c2 << endl;
	cout << c1 * c2 << endl;
	cout << c1 / c2 << endl;

	cout << "---------------------------------\n";

	Complex c3(3, Fraction(1 , 2));
	cout << c3 << endl;

	Complex c4(Fraction(-3,4), 2);
	cout << c4 << endl;

	cout << c3 + c4 << endl;
	cout << c3 - c4 << endl;
	cout << c3 * c4 << endl;
	cout << c3 / c4 << endl;

	system("pause");
	return 0;
} 

