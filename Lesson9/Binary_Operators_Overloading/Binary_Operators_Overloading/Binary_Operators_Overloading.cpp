// Binary_Operators_Overloading.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Test t1(5);
	t1.Show();
	Test t2(10);
	t2.Show();
	Test t3;
	t3.Show();
	t3 = 25 + t1;
	cout << "-----------------------------------\n";
	t3.Show();
	t1.Show();

	system("pause");
	return 0;
}

