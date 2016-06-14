// Solve_Expression.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

template<class T>
class Stack
{
	//максимальный размер стека
	int maxSize;
	//текущая вершина стека
	int top;
	//стек - массив данных
	T *ptr;
public:
	Stack(int size = 0) :maxSize(size)
	{
		ptr = new T[size];
		top = -1;
	}
	~Stack()
	{
		if (ptr)
			delete[] ptr;
	}
	bool Empty()
	{
		return top == -1;
	}

	bool Full()
	{
		return top == maxSize - 1;
	}
	void Push(T data)
	{
		if (!Full())
			ptr[++top] = data;
		else
			cout << "Stack is Full!!!\n";
	}
	T Pop()
	{
		if (!Empty())
			return ptr[top--];
		else
		{
			cout << "Stack is Empty!!!\n";
			return -1;
		}
	}
	void ShowStack()
	{
		for (int i = 0; i <= top; i++)
			cout << ptr[i] << "\t";
		cout << endl;
	}
};

//разбор введенного выражения
char* analis(char* str)
{
	Stack<char> st1(20);
	char chv, chs;//chv-символ строки chs - символ из стека
	int index = 0;//индекс в результирующей строке по которому происходит запись
	char* strResult = new char[strlen(str) + 1];//результирующая строка
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] >= '0'&&str[i] <= '9')
			strResult[index++] = str[i];
		else
		{
			if (i==0||st1.Empty() || str[i] == '(') //если стек пуст или встретилась открывающаяся скобка
				st1.Push(str[i]);
			else
			{
				switch (str[i])
				{
				case ')':
					while (!st1.Empty())
					{
						chs = st1.Pop();
						if (chs== '(')
							break;
						strResult[index++] = chs;
					}
					break;
				case '*':
				case '/':
					st1.Push(str[i]);
					break;
				case '+':
				case '-':
					chs = st1.Pop();
					while (chs== '*'||chs == '/')
					{
						strResult[index++] = chs;
						chs = st1.Pop();
					}
					st1.Push(chs);
					st1.Push(str[i]);
					break;
				}

			}
		}
	}
	//если в стеке что-то осталось переносим все в результирующую строку
	while (!st1.Empty())
		strResult[index++] = st1.Pop();
	strResult[index] = '\0';
	return strResult;
}

int solve(char* str)
{
	Stack<float> st1(20);
	float sum;
	int i = 0;//текущий индекс строки
	float ch1, ch2;//первый и второй операнды
	do
	{

		while (str[i] >= '0' && str[i] <= '9')
		{
			st1.Push(float(str[i] - '0'));
			i++;
		}
		ch2 = st1.Pop();
		ch1 = st1.Pop();
		switch (str[i])
		{
		case '+':sum = ch1 + ch2; break;
		case '-':sum = ch1 - ch2; break;
		case '*':sum = ch1 * ch2; break;
		case '/':sum = ch1 / ch2; break;
		}
		st1.Push(sum);
		i++;
	} while (str[i] != '\0');
	sum = st1.Pop();
	return sum;
}


int _tmain(int argc, _TCHAR* argv[])
{
	char strExpression[256],strOPZ[256];
	cout << "Enter string for solve:"<<endl;
	cin >> strExpression;
	strcpy_s(strOPZ, 256, analis(strExpression));
	cout << "-------OPZ---------------------\n";
	cout << strOPZ<<endl;
	cout << "-------Result---------------------\n";
	cout << "Result=" << solve(strOPZ) << endl;

	system("pause");
	return 0;
}

