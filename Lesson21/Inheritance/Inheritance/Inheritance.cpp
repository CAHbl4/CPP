// Inheritance.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class A
{
private:
	int a1;
protected:
	int a2;
public:
	int a3;
	A(int a1 = 0, int a2 = 0, int a3 = 0) :a1(a1), a2(a2), a3(a3)
	{
		cout << "Constructor A!!!\n";
	}
	void FA()
	{
		cout << "Method A::FA\n";
		cout << "Data A: " << a1 <<", "<<a2<<","<<a3<<endl;
	}
	~A()
	{
		cout << "Destructor A!!!\n";
	}
};

//наследник класса А
class B: protected A
{
	int bb;
public:
	B(int a1 = 0, int a2=0, int a3=0,int b = 0) :A(a1,a2,a3), bb(b)
	{
		cout << "Constructor B!!!\n";
	}
	void FB()
	{
		cout << "Method B::FB\n";
		FA();
		cout << "Data B: " << bb << endl;
		//видимые поля класса A
		//a1 не доступно поскольку private
		//cout << "a1:" << a1 << endl;
		cout << "a2:" << a2 << endl;
		cout << "a3:" << a3 << endl;

	}
	~B()
	{
		cout << "Destructor B!!!\n";
	}
};

class C :public B
{
	int cc;
public:
	C(int a1 = 0, int a2 = 0, int a3 = 0, int b = 0, int c = 0) :B(a1, a2, a3, b) , cc(c)
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
		FB();
		//видимые поля класса A
		//a1 не доступно поскольку private
		//cout << "a1:" << a1 << endl;
		cout << "a2:" << a2 << endl;
		cout << "a3:" << a3 << endl;
	}
};



int _tmain(int argc, _TCHAR* argv[])
{
	{
		//В классе A a1-private, a2-protected, a3-public
		A a(1,2,3);
		a.FA();
		B b(1, 2,3,4);
		b.FB();
		C c(1, 2, 3, 4, 5);
		c.FC();
				
		
	}
	system("pause");
	return 0;
}
