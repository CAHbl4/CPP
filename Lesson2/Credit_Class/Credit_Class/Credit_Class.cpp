// Credit_Class.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Credit.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Rus");

	Credit man1;
	man1.Info();

	Credit man2("Иванов");
	man2.Info();

	system("pause");
    return 0;
}

