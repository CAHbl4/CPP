#pragma once
#include <iostream>
#include "Node.h"

template <class T>
class LinkedStack {
	Node<T>* head;
	Node<T>* tail;
	int size;
public:
	LinkedStack() : head(nullptr), tail(nullptr), size(0) {}

	bool Empty() const {
		return head == nullptr;
	}

	void Push(T data) {
		++size;
		if (Empty()) {
			head = new Node<T>;
			head->data = data;
			head->next = nullptr;
			tail = head;
		}
		else {
			tail->next = new Node<T>;
			tail = tail->next;
			tail->data = data;
			tail->next = nullptr;
		}
	}

	T Pop() {
		if (!Empty()) {
			--size;
			T result = tail->data;
			if (head == tail) {
				delete head;
				head = tail = nullptr;
			}
			else {
				Node<T>* tmp = head;
				while (tmp->next->next)
					tmp = tmp->next;
				delete tail;
				tail = tmp;
				tail->next = nullptr;
			}
			return result;
		}
		throw std::out_of_range("Stack empty!");
	}

	T Peek() {
		return tail->data;
	}

	void Clear() {
		Node<T>* tmp;
		while (head) {
			tmp = head;
			head = tmp->next;
			delete tmp;
		}
		head = tail = nullptr;
		size = 0;
	}

	void Show() const {
		if (!Empty()) {
			Node<T> *tmp = head;
			do{
				std::cout << tmp->data << "\t";
				tmp = tmp->next;
			} while (tmp);
		}
		else
			std::cout << "Stack empty!";
		std::cout << std::endl;
	}

	~LinkedStack() {
		Clear();
	}
};
