// Test2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	//fstream fs("test.txt", ios::out | ios::trunc);
	//char out[256] = { '\0' };

	//for (int i = 0; i < 255; ++i) {
	//	out[i] = '0' + i % 10;
	//}

	//for (int i = 0; i < 0x00800000; ++i) {
	//	fs << out;
	//}

	//fs.close();

	fstream fin("test.txt", ios::in);
	fin.seekg(0, ios::end);
	cout << fin.tellg();
	fin.close();
	
	system("pause");
	return 0;
}

