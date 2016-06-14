// Priority_Queue.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

//класс для хранении данных и приоритета
//создаем шаблон
template<class T>
class Pair
{
	T data;
	int prioritet;
public:
	Pair(T one = 0, int two = 0) :data(one), prioritet(two)
	{}
	//установка значений в паре
	void SetPair(T one, int two)
	{
		data = one;
		prioritet = two;
	}
	void ShowPair()
	{
		cout << data << " : " << prioritet;
	}
	//перегрузка оператора сравнения
	bool operator<(const Pair<T>& Obj)
	{
		return prioritet < Obj.prioritet;
	}
};

template<class T>
class PriorityQueue
{
	int maxSize;
	int length;
	Pair<T> *ptr;
public:
	PriorityQueue(int size = 0) :maxSize(size), length(0)
	{
		ptr = new Pair<T>[size];
	}
	~PriorityQueue()
	{
		if (ptr)
			delete[] ptr;
	}
	bool Empty()
	{
		return length == 0;
	}
	bool Full()
	{
		return length == maxSize;
	}
	//добавление элементов в очередь
	void Push(T data, int prioritet)
	{
		if (!Full())
		{
			Pair<T> temp(data, prioritet);
			ptr[length++] = temp;
			if (length > 1)
			{
				int index = length - 2;
				while (ptr[index] < ptr[index + 1] && index != 0)
				{
					ptr[index + 1] = ptr[index];
					ptr[index] = temp;
					--index;
				}
			}
		}
		else
			cout << "Queue is full!!!\n";
	}
	Pair<T> Pop()
	{
		if (!Empty())
		{
			Pair<T> temp = ptr[0];
			for (int i = 1; i < length; i++)
				ptr[i - 1] = ptr[i];
			--length;
			return temp;
		}
		else
		{
			cout << "Queue is empty!!!\n";
			exit(1);
		}
	}
	void Show()
	{
		for (int i = 0; i < length; i++)
		{
			ptr[i].ShowPair();
			cout << "\t";
		}
		cout << endl;
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	PriorityQueue<char> pr1(5);
	pr1.Push(1, 20);
	pr1.Push(1, 10);
	pr1.Push(10, 0);
	pr1.Push(8, 5);
	pr1.Push(11, 2);
	pr1.Show();
	system("pause");
	return 0;
}

