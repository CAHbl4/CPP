// Task4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "String.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[]) {
	String str("Hello");
	cout << str << endl;
	str[str('e')] = 'a';
	cout << str << endl;

	cout << int(str) << endl;

	system("pause");
	return 0;
}
