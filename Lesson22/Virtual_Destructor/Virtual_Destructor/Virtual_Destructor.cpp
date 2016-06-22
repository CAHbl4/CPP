// Virtual_Destructor.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Base
{
public:
	Base(){ cout << "Base Constructor!!!\n"; }
	virtual ~Base(){ cout << "Base Destructor!!!\n"; }
};

class Derive :public Base
{
public:
	Derive(){ cout << "Derive Constructor!!!\n"; };
	~Derive(){ cout << "Derive Destructor!!!\n"; };
};

int _tmain(int argc, _TCHAR* argv[])
{
	Base *ptr = new Base;
	delete ptr;
	Derive *ptr1 = new Derive;
	delete ptr1;
	cout << "------------------------------\n";
	ptr = new Derive;
	delete ptr;

	system("pause");
	return 0;
}

