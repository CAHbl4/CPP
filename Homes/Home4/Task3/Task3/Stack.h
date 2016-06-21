#pragma once

template<class T>
class Stack {
	int size;
	T *ptr;
	int top;

public:
	Stack(int size = 0) :size(size) {
		ptr = new T[size];
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

	void Push(T val) {
		if (!Full())
			ptr[++top] = val;
		else
			cout << "Stack Full!\n";
	}

	T Pop() {
		if (!Empty())
			return ptr[top--];
		cout << "Stack Empty!\n";
		return -1;
	}

	void Show() const {
		for (int i = 0; i <= top; ++i) {
			cout << ptr[i] << "\t";
		}
		cout << endl;
	}

};