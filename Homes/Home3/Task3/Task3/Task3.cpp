// Task3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "String.h"
#include "Array.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	String s1("Hello");
	/*
	В 2013 студии вызовется все равно конструктор копирования, конструктор переноса реализован в 15й студии
	http://stackoverflow.com/a/26581337
	*/
	String s2(s1); 
	cout << s2 << endl;

	cout << "--------------------------------------------------\n";
	Array a1(5);
	a1.Show();
	Array a2(a1);
	a2.Show();

	system("pause");
	return 0;
}

