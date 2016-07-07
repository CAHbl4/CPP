// Unique_ptr.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <memory>

using namespace std;

//функция, возвращающая указатель на строку
unique_ptr<string> demo(string str)
{
	cout << str << endl;
	return unique_ptr<string>(new string);
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	//создаем указатель на строку
	unique_ptr< string> pul(new string("Hello!"));
	//просто указатель
	unique_ptr< string> pu2;
	//pu2 = pul; // #1 не разрешено 
	unique_ptr<string> pu3;
	pu3 = unique_ptr<string>(new string("Yo!")); // #2 разрешено 

	unique_ptr<string> psl, ps2;
	psl = demo("Uniquely special");
	
	// делает возможным присваивание 
	psl = demo(" and more");
	cout << *ps2 << *psl << endl;


	system("pause");


	return 0;
}

