// Binary_Files.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	int a = 200;
	float pi = 3.14;
	char ch = 'Z';
	char* str = "Hello!!!";
	//запись данных в бинарный файл
	try
	{
		//открытие файла для записи в бинарном режиме
		/*fstream outfile("test.dat", ios::out | ios::binary);
		if (!outfile)
			throw exception("Error!!!\n");
		outfile.write(reinterpret_cast<char*>(&a), sizeof(a));
		outfile.write(reinterpret_cast<char*>(&pi), sizeof(pi));
		outfile.write(&ch, sizeof(ch));
		outfile.write(str, strlen(str)+1);
		outfile.close();*/

		//считывание из бинарного файла 
		fstream infile("test.dat", ios::in|ios::binary);
		if (!infile)
			throw exception("Error!!!\n");
		char str1[256];
		infile.read(reinterpret_cast<char*>(&a), sizeof(a));
		infile.read((char*)(&pi), sizeof(pi));
		infile.read(&ch, sizeof(ch));
		infile.read(str1, strlen(str) + 1);
		cout << "a=" << a << endl;
		cout << "pi=" << pi << endl;
		cout << "ch=" << ch << endl;
		cout << "str1=" << str1 << endl;
		infile.close();
	}
	catch (exception& e)
	{
		cout << e.what();
	}

	system("pause");
	return 0;
}

