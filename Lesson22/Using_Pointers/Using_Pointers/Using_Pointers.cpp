// Using_Pointers.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

//базовый класс
class A
{
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
	virtual void Show()
	{
		cout << "Method Show class A!!!\n";
		cout << "Data: " << a << endl;
	}
};

//производный класс
class B:public A
{
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
	virtual void Show()
	{
		cout << "Method Show class B!!!\n";
		cout << "Data: " << b << endl;
	}
};

//производный от класса B
class C:public B
{
	int c;
public:
	C(int a = 0, int b = 0, int c = 0) :B(a, b), c(c)
	{
		cout << "Constructor C!!!\n";
	}
	~C()
	{
		cout << "Destructor C!!!\n";
	}
	void Show()
	{
		cout << "Method Show class C!!!\n";
		cout << "Data: " << c << endl;
	}
};



int _tmain(int argc, _TCHAR* argv[])
{
	A a(1);
	a.Show();
	B b(2, 3);
	b.Show();
	C c(4, 5, 6);
	c.Show();
	cout << "---------------------------------\n";
	//работа через указатели
	A *ptrA = &a;
	ptrA->Show();
	B *ptrB = &b;
	ptrB->Show();
	C *ptrC = &c;
	ptrC->Show();
	cout << "---------------------------------\n";
	//работа через указатель базового класса
	//указатель указывает на объект класса А
	ptrA->Show();
	//указатель указывает на объект класса B
	ptrA = &b;
	ptrA->Show();
	//указатель указывает на объект класса C
	ptrA = &c;
	ptrA->Show();
	cout << "---------------------------------\n";
	ptrB = &b;
	ptrB->Show();
	ptrB = &c;
	ptrB->Show();
	cout << "---------------------------------\n";
	//формирование массива объектов
	A mas[3] = { a, b, c };
	for (int i = 0; i < 3; i++)
		mas[i].Show();
	//работа через массив указателей
	A *mas1[3] = { &a, &b, &c };
	for (int i = 0; i < 3; i++)
		mas1[i]->Show();
	system("pause");
	return 0;
}

