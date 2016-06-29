// Test_Class_Array.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Array
{
	int size;
	int *ptr;
public:
	class Exception
	{
	public:
		char* name;
		int x;
		Exception(char* str, int x) :x(x)
		{
			name = new char[strlen(str) + 1];
			strcpy_s(name, strlen(str) + 1, str);
			
		}
		~Exception()
		{
			cout << "Destructor Exception!!!\n";
			if (name)
				delete[] name;
		}
		void What()
		{
			cout << name << endl << "value=" << x << endl;
		}
		Exception(const Exception& Obj)
		{
			name = new char[strlen(Obj.name) + 1];
			strcpy_s(name, strlen(Obj.name) + 1, Obj.name);
			x = Obj.x;
		}
	};
	Array(int size = 0) :size(size)
	{
		if (size <= 0)
			throw Exception("Wrong size!!!",size);
		cout << size << endl;
		ptr = new int[size];
		if (!ptr)
			throw size;
		for (int i = 0; i < size; i++)
			ptr[i] = rand() % 100;
	}
	int operator[](int index)
	{
		if (index < 0 || index >= size)
			throw Exception("Wrong index!!!",index);
		return ptr[index];
	}
	void Show()
	{
		for (int i = 0; i < size; i++)
			cout<<ptr[i]<<"\t";
		cout << endl;
	}
	~Array()
	{
		if (ptr)
			delete[] ptr;
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	try
	{
		Array ar1(5000000000);
		ar1.Show();
		cout << "ar1[2]=" << ar1[20] << endl;
	}
	catch (int x)
	{
		cout << "x=" << x << ", but what is this?\n";
		cout << "What's wrong!!!\n";
	}
	catch (char* str)
	{
		cout << str << endl;
	}
	catch (Array::Exception ex)
	{
		ex.What();
	}
	catch (bad_alloc ex)
	{
		cout << ex.what() << endl;
	}
	system("pause");
	return 0;
}

