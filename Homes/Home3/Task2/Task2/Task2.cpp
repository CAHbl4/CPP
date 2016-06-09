// Task2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Overcoat.h"
#include "Flat.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	Overcoat c1("Coat 1", PaddockCoat, 100);
	cout << c1;
	Overcoat c2("Coat 2", PaddockCoat, 105);
	cout << c2;
	Overcoat c3("Coat 3", ChesterfieldCoat, 105);
	cout << c3;

	c2 == c3 ? cout << "c2 == c3\n" : cout << "c2 != c3\n";
	c1 > c2 ? cout << "c1 > c2\n" : cout << "c1 <= c2\n";

	cout << "--------------------------------------------------\n";
	Flat f1(20.2, 20600);
	cout << f1 << endl;
	Flat f2(20.2, 20500);
	cout << f2 << endl;
	Flat f3(41.3, 45000);
	cout << f3 << endl;

	f2 == f3 ? cout << "f2 == f3\n" : cout << "f2 != f3\n";
	f1 > f2 ? cout << "f1 > f2\n" : cout << "f1 <= f2\n";

	system("pause");
	return 0;
}

