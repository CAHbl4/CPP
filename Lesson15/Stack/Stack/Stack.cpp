// Stack.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Stack {
	int size;
	int *ptr;
	int top;

public:
	Stack(int size = 0) :size(size) {
		ptr = new int[size];
		top = -1;
	}

	~Stack() {
		if (ptr)
			delete[] ptr;
	
	}

	bool Empty() const {
		return top == -1;
	}

	bool Full() const {
		return top == size - 1;
	}

	void Push(int val) {
		if (!Full())
			ptr[++top] = val;
		else
			cout << "Stack Full!\n";
	}

	int Pop() {
		if (!Empty())
			return ptr[top--];
		cout << "Stack Empty!\n";
		return -1;
	}

	void Show() const {
		for (int i = 0; i <=top; ++i) {
			cout << ptr[i] << "\t";
		}
		cout << endl;
	}
	
};

int _tmain(int argc, _TCHAR* argv[])
{
	Stack st1(5);
	st1.Push(1);
	st1.Push(2);
	st1.Push(3);
	st1.Push(4);
	st1.Push(5);
	st1.Push(6);
	st1.Push(7);

	st1.Show();

	while (!st1.Empty()) {
		cout << st1.Pop() << endl;
		st1.Show();
	}


	system("pause");
	return 0;
}

