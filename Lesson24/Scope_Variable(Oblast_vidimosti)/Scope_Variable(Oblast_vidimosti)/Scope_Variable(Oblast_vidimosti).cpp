// Scope_Variable(Oblast_vidimosti).cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include"A.h"
#include "B.h"

//������������� ��������� using
//���������� ��� ������������ ���� std
//� ���������� �� ����� � ����������, ��������
//�������, �� �������� ������� ��������� 
using namespace std;

//������������� ���������� using
//��������� ���������� ������ ����� ������������ ����
using Test1::B;
using Test1::A;

void f1(int a, int x)
{
	//��������� �������������� ����������
	//������� ��������� - ������� f1()
	cout << "a=" << a << ", x=" << x << endl;
	static int z;
	cout << "z=" << z++ << endl;

}

//const int STAVKA = 15;
int STAVKA;

namespace Test1
{
	int a = 100;
	double x = 200;
}

int a = 111111;
namespace Test2
{
	int a = -100;
	double x = -200;
	void f1(int a, int x)
	{
		//��������� �������������� ����������
		//������� ��������� - ������� f1()
		cout << "a=" << a << ", x=" << x << endl;
		static int z;
		cout << "z=" << z++ << endl;
	}

}
	namespace Test1
	{
		void f1();
		int b=25, c=50;
		
	}

	using Test2::f1;


int _tmain(int argc, _TCHAR* argv[])
{
	//��������� �������������� ����������
	//������� ��������� - ������� _tmain()
	int a=4;
	double x = 6;
	cout << "a=" << a << ", x=" << x << endl;
	cout << "STAVKA=" << STAVKA << endl;

	//��������� � ����������, ��������� � ������������ ����
	cout << "Namespace Test1\n";
	cout << "a=" << Test1::a << ", x=" << Test1::x << endl;
	cout << "Namespace Test2\n";
	cout << "a=" << Test2::a << ", x=" << Test2::x << endl;
	cout << "c=" << Test1::c << ", b=" << Test1::b << endl;
	
	{
		//��������� �������������� ����������
		//������� ��������� - ������� ���� {}
		int a = 1;
		double x = 2;
		cout << "a=" << a << ", x=" << x << endl;
		cout << "STAVKA=" << STAVKA << endl;
	}
	//��������� �������������� ����������
	//������� ��������� - ���� for
	for (int i = 0, j = 8; i < 3; i++, j--)
	{
		cout << "i=" << i << ", j=" << j << endl;
		cout << "STAVKA=" << STAVKA << endl;
	}
	Test2::f1(10, 20);
	//::f1(11, 21);
	//::f1(12, 22);
	system("pause");
	system("cls");
	A a1;
	a1.Show();
	cout << "Global a=" << ::a << endl;
	

	system("pause");
	return 0;
}

