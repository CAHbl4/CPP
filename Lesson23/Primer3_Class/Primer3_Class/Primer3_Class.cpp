// Primer3_Class.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

const int Max = 3;
class Stack
{
	int st[Max];
	int top;
public:
	class Exception
	{
	public:
		char str[20];
		Exception(char *str1)
		{
			strcpy_s(str, strlen(str1) + 1, str1);
		}
	};
	Stack()
	{
		top = 0;
	}
	int pop()
	{
		if (top <= 0)
			throw Exception("Error in POP");
		return st[--top];
	}
	void push(int value)
	{
		if (top >= Max)
			throw Exception("Error in PUSH");
		st[top++] = value;
	}

};


int _tmain(int argc, _TCHAR* argv[])
{
	Stack st1;
	try
	{
		st1.push(1);
		st1.push(2);
		st1.push(3);
		//st1.push(4);
		cout << st1.pop()<<"\t";
		cout << st1.pop()<< "\t";
		cout << st1.pop()<< "\t";
		cout << st1.pop()<< "\t";

	}
	catch (Stack::Exception obj)
	{
		cout << obj.str << endl;

	}
	system("pause");
	return 0;
}

