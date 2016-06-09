// Array_Pair.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	Pair<int, int> p1(1, 2);
	p1.ShowPair();

	Pair<char*, int> p2("password", 12345);
	p2.ShowPair();

	Pair<char*, char*> p3("password", "qwerty");
	p3.ShowPair();

	Array<int,int> a1(3);
	a1.SetArray();
	a1.Show();

	Array<char* , char* > a2(3);
	a2.SetArray();
	a2.Show();

	system("pause");
	return 0;
}

