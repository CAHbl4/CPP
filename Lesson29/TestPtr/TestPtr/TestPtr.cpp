// TestPtr.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <string>
#include <memory>
#include <iostream>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	string *str = new string("Hello world!");
	
	shared_ptr<string> sptr1(str);

	cout << *sptr1 << endl;
	shared_ptr<string> sptr2(str);
	cout << *sptr2 << endl;
	
	system("pause");
	return 0;
}

