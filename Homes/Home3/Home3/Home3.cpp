// Home3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "String.h"


int main()
{
	String str1(5);
	cout << "Input string 1 (length = "<< str1.GetLength() << "): ";
	str1.InputString();
	cout << "String 1: ";
	str1.ShowString();

	String str2("Hello world!");
	cout << "String 2: " << str2.GetString() << endl;

	String str3;
	cout << "Input string 3 (length = " << str3.GetLength() << "): ";
	str3.InputString();
	str3.ShowString();

	cout << "Totally strings created: " << String::GetCreated() << endl;

	system("pause");
    return 0;
}

