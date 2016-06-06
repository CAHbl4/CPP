// SmartPointer.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class SmartPointer
{
	int *ptr;
public:
	SmartPointer() :ptr(NULL){};
	int operator*()
	{
		return *ptr;
	}
	~SmartPointer()
	{
		cout << "Destructor!!!\n";
		if (ptr)
			delete ptr;
	}
};

void Funct1()
{
	int *ptr = new int;
	*ptr = 5;
	//
	//

	cout << "In Function!!!\n";
	cout << "Data: " << *ptr << ", adress: " << ptr << endl;
	SmartPointer p1;
	return;
}


int _tmain(int argc, _TCHAR* argv[])
{
	int *ptr = new int;
	*ptr = 5;
	Funct1();
	cout << "OUT Function!!!\n";
	cout << "Data: " << *ptr << ", adress: " << ptr << endl;
	system("pause");
	return 0;
}

