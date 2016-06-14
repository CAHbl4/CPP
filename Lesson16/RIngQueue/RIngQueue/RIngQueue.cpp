// RIngQueue.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class RingQueue
{
	//максимальный размер очереди
	int maxSize;
	//текущий размер очереди
	int length;
	//очередь - массив целочисленных элементов
	int *ptr;
public:
	RingQueue(int size) :maxSize(size), length(0)
	{
		ptr = new int[size];
	}
	~RingQueue()
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
	void Push(int data)
	{
		if (!Full())
			ptr[length++] = data;
		else
			cout << "RingQueue is empty!!!\n";
	}
	int Pop()
	{
		int temp;
		if (!Empty())
		{
			temp = ptr[0];
			for (int i = 1; i < length; i++)
				ptr[i - 1] = ptr[i];
			ptr[length - 1] = temp;
			return temp;
		}
		else
		{
			cout << "RingQueue is empty!!!\n";
			return -1;
		}
	}

	void Show()
	{
		for (int i = 0; i < length; i++)
			cout << ptr[i] << "\t";
		cout << endl;
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	RingQueue rq1(5);
	rq1.Push(1);
	rq1.Push(2);
	rq1.Push(3);
	rq1.Show();
	cout << rq1.Pop() << endl;
	rq1.Show();
	rq1.Push(4);
	rq1.Show();
	cout << rq1.Pop() << endl;
	rq1.Show();
	system("pause");
	return 0;
}

