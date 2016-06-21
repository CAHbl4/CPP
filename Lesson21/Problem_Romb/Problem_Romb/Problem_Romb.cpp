// Problem_Romb.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class A
{
protected:
	int a;
public:
	A(int a = 0) :a(a)
	{
		cout << "Constructor A!!!\n";
	}
	~A()
	{
		cout << "Destructor A!!!\n";
	}
	void ShowA()
	{
		cout << "Method A::Show()\n";
		cout << "Data A:" << a << endl;
	}
};

//наследник класса A
class B:public virtual A
{
protected:
	int b;
public:
	B(int a = 0, int b = 0) :A(a), b(b)
	{
		cout << "Constructor B!!!\n";
	}
	~B()
	{
		cout << "Destructor B!!!\n";
	}
	void ShowB()
	{
		cout << "Method B::Show()\n";
		ShowA();
		cout << "Data B:" << b << endl;
	}
};

//наследник класса А
class C:public virtual A
{
protected:
	int c;
public:
	C(int a = 0, int c = 0) :A(a), c(c)
	{
		cout << "Constructor C!!!\n";
	}
	~C()
	{
		cout << "Destructor C!!!\n";
	}
	void ShowC()
	{
		cout << "Method C::Show()\n";
		ShowA();
		cout << "Data C:" << c << endl;
	}
};

//наследник класса B и класса C
class D :public B, public C
{
	int d;
public:
	D(int a, int b, int c, int d) :B(3, b), C(10, c), d(d), A(a)
	{
		cout << "Constructor D!!!\n";
	}
	~D()
	{
		cout << "Destructor D!!!\n";
	}
	void ShowD()
	{
		cout << "Method D::Show()\n";
		cout << "Data BA: " << B::a << endl;
		cout << "Data B: " << b << endl;
		cout << "Data CA: " << C::a << endl;
		cout << "Data C: " << c << endl;
		cout << "Data D: " << d << endl;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	
	{
		A a1(1);
	a1.ShowA();
	B b1(2, 3);
	b1.ShowB();
	C c1(4, 5);
	c1.ShowC();
	cout << "--------------------------------------------\n";

	D d1(1, 2, 3, 4);
	d1.ShowD();

	}
	system("pause");
	return 0;
}

