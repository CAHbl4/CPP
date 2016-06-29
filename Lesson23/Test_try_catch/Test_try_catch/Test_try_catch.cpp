// Test_try_catch.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void f1(int a, int b)
{
	cout << "Function f1!!!\n";
	throw 2;
}

int _tmain(int argc, _TCHAR* argv[])
{
	//помещаем код, где могут быть ошибки в контролируемый блок try
	try
	{
		//деление двух чисел
		double a = 5, b = 2;
		if (b == 0) throw "Abnormal!!!";
		cout << "a/b=" << a / b << endl;
		f1(3, 4);
	}
	catch (int)
	{
		cout << "Exception int!!!\n";
	}
	catch (double)
	{
		cout << "Exception double!!!\n";
	}

	catch (...)
	{
		cout << "Devision by zero!\n";
	}
	system("pause");
	return 0;
}

