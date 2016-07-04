// Const_cast.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Test {
public:
	Test(int a, int b);
	void print() const;
private:
	int number;
	const int data;
};

Test::Test(int a, int b) :number(a), data(b) {}

void Test::print() const {
	cout << "\nBefore n : " << number << ", data:" << data<<endl;
	//��������� const � ������ print(), ����������� ��������� �������� �����
	const_cast< Test * >(this)->number = 1111;
	int *ptr;
	//��������� const c ���� data
	ptr = const_cast< int * >(&data);
	//���������� ��������
	*ptr = 2222;
	cout << "After: n : " << number << ", data:" << data<<endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	const int a = 100;
	cout << "Const a=" << a << endl;
	//��������� ��������� ���������
	//a = 200;
	const int *ptr = &a;
	cout << "Const a=" << *ptr << endl;
	//�������� 
	int *ptrNew = const_cast<int *>(ptr);
	*ptrNew = 200;
	cout << "Const a=" << *ptr+5 << endl;

	//������ � �������
	Test X(1, 2);
	X.print();
	X.print();
	system("pause");
	return 0;
}

