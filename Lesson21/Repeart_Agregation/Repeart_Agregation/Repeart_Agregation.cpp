// Repeart_Agregation.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class A
{
	int aa;
public:
	A(int a = 0) :aa(a)
	{
		cout << "Constructor A!!!\n";
	}
	void FA()
	{
		cout << "Method A::FA\n";
		cout << "Data A: " << aa << endl;
	}
	~A()
	{
		cout << "Destructor A!!!\n";
	}
};

//Композиция
class B
{
	int bb;
	A obj;
public:
	B(int a = 0, int b = 0) :obj(A(a)), bb(b)
	{
		cout << "Constructor B!!!\n";
	}
	void FB()
	{
		cout << "Method B::FB\n";
		obj.FA();
		cout << "Data B: " << bb << endl;
	}
	~B()
	{
		cout << "Destructor B!!!\n";
	}
};

//Агрегация

class C
{
	int cc;
	A* obj;
public:
	C(A* a, int c) :cc(c), obj(a)
	{
		cout << "Constructor C!!!\n";
	}
	~C()
	{
		cout << "Destructor C!!!\n";
	}
	void FC()
	{
		cout << "Method C::FC\n";
		obj->FA();
		cout << "Data C: " << cc << endl;
	}

};


int _tmain(int argc, _TCHAR* argv[])
{
	{
		A a;
		a.FA();
		B b(1, 2);
		b.FB();
		C c(&a, 3);
		c.FC();
	}
	system("pause");
	return 0;
}

