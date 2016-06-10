// Queue.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Queue {
	//максимальный размер очереди
	int maxSize;
	//текущий размер очереди
	int length;
	//очередь - массив данных
	int* ptr;
public:
	Queue(int size = 0) : maxSize(size), length(0) {
		ptr = new int[size];
	}

	~Queue() {
		if (ptr)
			delete[] ptr;
	}

	bool Empty() const {
		return length == 0;
	}

	bool Full() const {
		return length == maxSize;
	}

	void Push(int data) {
		if (!Full())
			ptr[length++] = data;
		else
			cout << "Queue is Full!!!\n";
	}

	int Pop() {
		if (!Empty()) {
			int temp = ptr[0];
			for (int i = 1; i < length; i++)
				ptr[i - 1] = ptr[i];
			--length;
			return temp;
		}
		else {
			cout << "Queue is Empty!!!\n";
			return -1;
		}
	}

	void ShowQueue() const {
		for (int i = 0; i < length; i++)
			cout << ptr[i] << "\t";
		cout << endl;
	}

};


int _tmain(int argc, _TCHAR* argv[]) {
	Queue q1(5);
	q1.Push(1);
	q1.Push(2);
	q1.Push(3);
	q1.Push(4);
	q1.Push(5);
	q1.Push(6);
	q1.ShowQueue();
	while (!q1.Empty()) {
		cout << q1.Pop() << endl;
		q1.ShowQueue();
	}
	system("pause");
	return 0;
}
