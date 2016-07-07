// Vvod_String_From File.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>
#include <fstream>
#include<string>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	string str;
	ifstream in("e:\\programm.cpp");
	/*while (in)
	{
		getline(in, str);
		cout << str << endl;
	}*/
	/*in.clear();
	in.seekg(0);*/
	
	cout << in.rdbuf() << endl;
	system("pause");
	return 0;
}

