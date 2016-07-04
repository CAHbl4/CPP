// TypeId.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
//нужен для определения типов во время выполнения
#include<typeinfo>
#include <ctime>

class Base
{
public:
	//виртуальный метод обязателен для динамической
	//индентификации типа
	virtual void Show()
	{
		std::cout << "ShowBase()!!!\n";
	}
};

class Derived:public Base
{
public:
	void Show()
	{
		std::cout << "ShowDerived!!!\n";
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(0));
	Base *ptr[10];
	for (int i = 0; i < 10; i++)
	{
		int k = rand() % 2;
		if (k == 0)
			ptr[i] = new Base();
		else
			ptr[i] = new Derived();
		std::cout << "Type:" << typeid(*ptr[i]).name() << std::endl;
		ptr[i]->Show();
	}

	system("pause");
	return 0;
}

