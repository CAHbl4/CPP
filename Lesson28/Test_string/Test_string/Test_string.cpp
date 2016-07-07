// Test_string.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	//создание строки
	string str1;
	str1 = "String One!\n";
	string str2 = "String Two!\n";
	string str3("String Three!\n");
	//вывод строки
	cout << str1 << str2 << str3;
	//ввод строки
	cout << "Enter string:";
	//ввод строки до разделителя
	cin >> str3;
	cout << str3<<endl;
	cout << "Enter string:";
	//ввод строки с разделителями
	//очищаем буфер ввода
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	getline(cin,str3,'\n');
	cout << str3 << endl;

	//приветсвие
	cout << "Enter your name:";
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	string greeting="Hello, ";
	string name;
	getline(cin, name);
	greeting += name + " ";
	cout << "Enter your surname:";
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	string surname;
	getline(cin, surname);
	greeting += surname + "!\nWe nice to meet you!!!\n";
	cout << greeting;

	//преобразование к char*
	char str10[256];
	strcpy_s(str10,256,greeting.c_str());
	cout << str10;
	const char *ptr;
	ptr = greeting.c_str();
	cout << ptr;
	system("pause");
	return 0;
}

