// Test2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	fstream fs("test.txt", ios::out | ios::trunc);

	for (int i = 0; i < 0x00FFFFFF; ++i) {
		fs << 'a';
	}

	fs.close();

	return 0;
}

