// Reinterpret_cast.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	int i;
	char *p = "This is a string";
	i = reinterpret_cast<int> (p);
	cout << i << endl;
	cout << "Convert i in string:" << reinterpret_cast<char *>(i) << endl;
	int a = 7;
	int *ip = &a;
	int temp = reinterpret_cast<int>(ip);
	cout << "Pointer value is" << ip << endl;
	cout << "Representation of a pointer as int is " << hex << temp << endl;
	struct dat { short a; short b; };
	long value = 0xA224B118;
	cout << "value=" << value << endl;
	dat * pd = reinterpret_cast<dat *> (&value);
	cout << " hex " << pd->a << endl;
	cout << " hex " << pd->b << endl;
	system("pause");
	return 0;
}

