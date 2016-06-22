// Using_Pointers.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

//������� �����
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

//����������� �����
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

//����������� �� ������ B
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
	//������ ����� ���������
	A *ptrA = &a;
	ptrA->Show();
	B *ptrB = &b;
	ptrB->Show();
	C *ptrC = &c;
	ptrC->Show();
	cout << "---------------------------------\n";
	//������ ����� ��������� �������� ������
	//��������� ��������� �� ������ ������ �
	ptrA->Show();
	//��������� ��������� �� ������ ������ B
	ptrA = &b;
	ptrA->Show();
	//��������� ��������� �� ������ ������ C
	ptrA = &c;
	ptrA->Show();
	cout << "---------------------------------\n";
	ptrB = &b;
	ptrB->Show();
	ptrB = &c;
	ptrB->Show();
	cout << "---------------------------------\n";
	//������������ ������� ��������
	A mas[3] = { a, b, c };
	for (int i = 0; i < 3; i++)
		mas[i].Show();
	//������ ����� ������ ����������
	A *mas1[3] = { &a, &b, &c };
	for (int i = 0; i < 3; i++)
		mas1[i]->Show();
	system("pause");
	return 0;
}

