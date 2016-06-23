// Override_Final.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Base
{
public:
	virtual void FuncA() 
	{
		cout << "Function Base::FuncA()\n";
	}
	virtual void FuncB(int data)
	{
		cout << "Function Base::FuncB()\n";
		cout << "Data:" << data << endl;
	}
	virtual ~Base()
	{
		cout << "Base Destructor!!!\n";
	}
};

class Derived :public Base
{
public:
	void FuncB(char* str)
	{
		cout << "Function Derives::FuncB()\n";
		cout << "Data:" << str << endl;
	}
	virtual void FuncA() final
	{
		cout << "Function Derived::FuncA()\n";
	}
	~Derived()
	{
		cout << "Derived Destructor!!!\n";
	}
};

class Derived2 :public Derived
{
public:
	/*virtual void FuncA()
	{
		cout << "Function Derived2::FuncA()\n";
	}*/

};
int _tmain(int argc, _TCHAR* argv[])
{
	{
		Base obj1;
		obj1.FuncA();
		obj1.FuncB(20);
		Derived obj2;
		//наследник обращается к методам базового класса
		obj2.FuncA();
		obj2.Base::FuncB(40);
		obj2.FuncB("11111");
		Derived2 obj3;
		obj3.FuncA();
	}
	system("pause");
	return 0;
}

