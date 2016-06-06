// Reference.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{

	int var1 = 10;
	int& var2 = var1;
	cout << "Var1 = " << var1 << ", Adress: " << &var1 << endl;
	cout << "Var2 = " << var2 << ", Adress: " << &var2 << endl;
	var2 = 25;
	cout << "Var1 = " << var1 << ", Adress: " << &var1 << endl;
	cout << "Var2 = " << var2 << ", Adress: " << &var2 << endl;
	var1 = 777;
	cout << "Var1 = " << var1 << ", Adress: " << &var1 << endl;
	cout << "Var2 = " << var2 << ", Adress: " << &var2 << endl;
	
	int&& var3 = 2 + 4;
	cout << "Var3 = " << var3 << ", Adress: " << &var3 << endl;

	var2 = var3;
	cout << "Var2 = " << var2 << ", Adress: " << &var2 << endl;
	cout << "Var1 = " << var1 << ", Adress: " << &var1 << endl;

	var2 = 7;
	cout << "Var3 = " << var3 << ", Adress: " << &var3 << endl;

	system("pause");
	return 0;
}

