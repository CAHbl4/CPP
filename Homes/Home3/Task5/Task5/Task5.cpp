// Task5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Date.h"
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	Date d1(1000000000);
	cout << d1 << endl;

	Date d2(31, 8, 2001, 1, 46, 40);
	cout << d2 << endl;

	Date d3(-1);
	cout << d3 << endl;

	d3 += 86400;
	cout << d3 << endl;


	system("pause");
	return 0;

}