// Bad_alloc.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	
		unsigned long long  SIZE =1000000000000000 ;
		char* ptr=nullptr;

		try
		{
			ptr = new char[SIZE];
		}
		catch (bad_alloc)
		{
			cout << "\n bad_alloc:\n";
			system("pause");
			return 0;
		}
		delete[] ptr;          
		cout << "\nOK.\n";
		system("pause");
		return 0;
}

