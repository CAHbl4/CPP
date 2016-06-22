#pragma once
#include "stdafx.h"
#include "Pair.h"
#include "Priority.h"

template <class T>
class PriorityQueue {
	int maxSize;
	int length;
	Pair<Priority, T>* ptr;
public:
	PriorityQueue(int size = 0) : maxSize(size), length(0) {
		ptr = new Pair<Priority, T>[size];
	}

	~PriorityQueue() {
		if (ptr)
			delete[] ptr;
	}

	bool Empty() const {
		return length == 0;
	}

	bool Full() const {
		return length == maxSize;
	}

	void Push(Priority priority, T data) {
		if (!Full()) {
			Pair<Priority, T> temp(priority, data);
			ptr[length++] = temp;
			if (length > 1) {
				int index = length - 2;
				while (ptr[index] < ptr[index + 1] && index >= 0) {
					ptr[index + 1] = ptr[index];
					ptr[index] = temp;
					--index;
				}
			}
		}
		else
			cout << "Queue is full!!!\n";
	}

	Pair<Priority, T> Pop() {
		if (!Empty()) {
			Pair<Priority, T> temp = ptr[0];
			for (int i = 1; i < length; i++)
				ptr[i - 1] = ptr[i];
			--length;
			return temp;
		}
		throw
			exit(1);
	}

	void Show() const {
		for (int i = 0; i < length; i++) {
			ptr[i].ShowPair();
			cout << "\t";
		}
		cout << endl;
	}
};
