#pragma once
#include <iostream>

template <class T>
struct Node {
	T data;
	Node<T>* next;
	Node<T>* prev;
};

template <class T>
class LinkedList {
	int size;
	int count;
	int grow;
	Node<T>* head;
	Node<T>* tail;

	void AddBack() {
		Node<T>* tmp = new Node<T>;
		tmp->data = T();
		tmp->next = nullptr;
		tmp->prev = nullptr;
		if (!head)
			head = tail = tmp;
		else {
			tmp->prev = tail;
			tail->next = tmp;
			tail = tmp;
		}
		++size;
	}

	void DelBack() {
		if (size) {
			if (head == tail) {
				delete head;
				head = nullptr;
				tail = nullptr;
			}
			else {
				tail = tail->prev;
				delete tail->next;
				tail->next = nullptr;
			}
			--size;
			if (count > size)
				count = size;
		}
	}

	Node<T>* GetPtrAtIndex(int index) const {
		if (index == 0)
			return head;

		if (index == size - 1)
			return tail;

		Node<T>* tmp;
		if (index < size / 2) {
			tmp = head;
			for (int i = 0; i < index; ++i)
				tmp = tmp->next;
		}
		else {
			tmp = tail;
			for (int i = 1; i < size - index; ++i)
				tmp = tmp->prev;
		}
		return tmp;
	}


public:
	LinkedList() : size(0), count(0), grow(1), head(nullptr), tail(nullptr) {}

	int GetSize() const {
		return size;
	}

	void SetSize(int size, int grow = 1) {
		while (this->size > size) {
			DelBack();
		}

		while (this->size < size) {
			AddBack();
		}

		this->grow = grow;
	}

	int GetUpperBound() const {
		return count - 1;
	}

	bool IsEmpty() const {
		return count;
	}

	void FreeExtra() {
		SetSize(count, grow);
	}

	void RemoveAll() {
		SetSize(0, grow);
	}

	T GetAt(int index) const {
		return operator[](index);
	}

	void SetAt(int index, T data) {
		operator[](index) = data;
	}

	T& operator[](int index) const {
		if (index >= 0 && index < count)
			return GetPtrAtIndex(index)->data;
		else
			throw std::out_of_range("Index out of bounds");
	}

	void Add(T data) {
		if (count == size) {
			SetSize(size + grow, grow);
		}
		GetPtrAtIndex(count)->data = data;
		++count;
	}

	void Append(const LinkedList<T>& other) {
		for (int i = 0; i < other.count; ++i)
			Add(other.GetAt(i));
	}

	LinkedList& operator=(const LinkedList& other) {
		if (this == &other)
			return *this;
		RemoveAll();
		SetSize(other.size, other.grow);
		Append(other);
		return *this;
	}

	T* GetData() {
		T* tmp = new T[count];
		for (int i = 0; i < count; ++i)
			tmp[i] = GetAt(i);
		return tmp;
	}

	void InsertAt(int index, T data) {
		if (index >= 0 && index < count) {
			Node<T>* tmp = GetPtrAtIndex(index);
			Node<T>* newNode = new Node<T>;
			newNode->data = data;
			newNode->prev = tmp->prev;
			newNode->next = tmp;
			tmp->prev->next = newNode;
			tmp->prev = newNode;
			++size;
			++count;
		}
		else
			throw std::out_of_range("Index out of bounds");
	}

	void RemoveAt(int index) {
		if (index >= 0 && index < count) {
			Node<T>* tmp = GetPtrAtIndex(index);
			tmp->prev->next = tmp->next;
			tmp->next->prev = tmp->prev;
			delete tmp;
			--size;
			--count;
		}
		else
			throw std::out_of_range("Index out of bounds");
	}

	void Show() const {
		std::cout << "Size: " << size << ", Grow: " << grow << std::endl;
		if (count) {
			std::cout << "Data:\n";
			Node<T>* tmp = head;
			for (int i = 0; i < count; ++i) {
				std::cout << tmp->data << "\t";
				tmp = tmp->next;
			}
		}
		else
			std::cout << "Array is empty.";
		std::cout << "\n--------------------------------\n";
	}

	~LinkedList() {
		RemoveAll();
	}
};
