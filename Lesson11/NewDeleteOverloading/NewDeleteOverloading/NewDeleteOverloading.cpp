// Peregruzka_New_Delete.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Test
{
	int data;
	//float x;
public:
	//Test(int value = 0) :data(value){}
	//перегрузка ввода-вывода
	friend istream& operator>>(istream& in, Test& Obj);
	friend ostream& operator<<(ostream& out, const Test& Obj);

	//перегрузка new delete
	void * operator new(size_t size)
	{
		cout << "Operator new!!!\n" << endl;
		cout << "Size:" << size << endl;
		void* ptr = malloc(size);
		if (ptr)
		{
			//заполняет память по указателю значением 0 (второй параметр)
			memset(ptr, 1, size);
			return ptr;
		}
		else
		{
			cout << "Error!!! Memory is out!!!";
			exit(0);
		}
	}

	void * operator new[](size_t size)
	{
		cout << "Operator new[]!!!\n" << endl;
		cout << "Size:" << size << endl;
		void* ptr = malloc(size);
		if (ptr)
		{
			memset(ptr, 0, size);
			return ptr;
		}
		else
		{
			cout << "Error!!! Memory is out!!!";
			exit(0);
		}
	}

	void operator delete(void* ptr)
	{
		cout << "Operator delete!!!\n" << endl;
		if (ptr)
			free(ptr);
	}

	void operator delete[](void* ptr)
	{
		cout << "Operator delete!!!\n" << endl;
		if (ptr)
			free(ptr);
	}


};

istream& operator>>(istream& in, Test& Obj)
{
	cout << "Enter data:";
	in >> Obj.data;
	return in;
}
ostream& operator<<(ostream& out, const Test& Obj)
{
	out << "Data: " << Obj.data << endl;
	return out;
}

int _tmain(int argc, _TCHAR* argv[])
{
	/*Test t1(7);
	cout << t1;
	Test t2;
	cin >> t2;
	cout << t2;*/

	Test *ptr = new Test;
	cout << *ptr << ", adress:" << ptr << endl;
	delete ptr;

	Test *ptr1 = new Test[2];
	cout << *ptr1 << ", adress:" << ptr1 << endl;
	delete[] ptr1;
	system("pause");
	return 0;
}

