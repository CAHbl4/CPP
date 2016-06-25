#pragma once
#include <iostream>

//����� ������ - ������������ �����
template <class T>
class List {
	//���������� ��������� � ������
	int size;
	//��������� �� ������ ������
	Node<T>* head;
	//��������� �� ����� ������
	Node<T>* tail;
public:
	List(): size(0), head(nullptr), tail(nullptr) {}

	List(const List& other): size(0), head(nullptr), tail(nullptr) {
		Node<T>* tmp = other.head;
		while (tmp) {
			AddBack(tmp->data);
			tmp = tmp->next;
		}
	}

	List& operator=(const List& other) {
		if (this == &other)
			return *this;
		Clear();
		Node<T>* tmp = other.head;
		while (tmp) {
			AddBack(tmp->data);
			tmp = tmp->next;
		}
		return *this;
	}

	void AddBack(T data) {
		//����������� ������ ������
		++size;
		//������� ����
		Node<T>* temp = new Node<T>;
		temp->data = data;
		temp->next = NULL;
		//���� ������ ����
		if (!head)
			head = tail = temp;
		//���� ������ �� ����
		else {
			//��������� ������� ������ ��������� � ����� (temp)
			tail->next = temp;
			//���������� ��������� ����� �� ����� �������
			tail = temp;
		}
	}

	void AddFront(T data) {
		//����������� ������ ������
		++size;
		//������� ����
		Node<T>* temp = new Node<T>;
		temp->data = data;
		temp->next = NULL;
		//���� ������ ����
		if (!head)
			head = tail = temp;
		//���� ������ �� ����
		else {
			//����� ������� ������ ��������� � ������
			temp->next = head;
			//���������� ��������� ������ �� ����� �������
			head = temp;
		}

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

	~List() {
		Clear();
	}

	//�������� ���������
	void DellBack() {
		Node<T>* temp = head;
		if (head) {
			--size;
			if (!head->next) {
				delete head;
				head = tail = NULL;
			}
			else {
				//��������� �� ������ �� �������������� ��������
				while ((temp->next)->next)
					temp = temp->next;
				//������� ��������� �������
				delete tail;
				//��������� tail �� �������������
				tail = temp;
				tail->next = NULL;
			}
		}
	}

	void DellFront() {

		Node<T>* temp = head;
		if (head) {
			--size;
			head = head->next;
			delete temp;
		}
	}

	//����� ������ ������
	void ShowList() const {
		std::cout << "Size:" << size << std::endl;
		//��������� ��������� ��� ��������� ������
		Node<T>* temp = head;
		while (temp) {
			//������� ������
			std::cout << temp->data << "\t";
			//��������� � ���������� ��������
			temp = temp->next;
		}
		std::cout << std::endl;
	}

	//������� � �������� �� ������������� �����
	void Add(int index, T data) {
		if (index < 0 || index >= size)
			std::cout << "Index is out of bound\n";
		else if (index == 0)
			AddFront(data);
		else if (index == size - 1)
			AddBack(data);
		else {
			++size;
			Node<T>* temp = new Node<T>;
			temp->data = data;
			int i = 0;
			//���������� ������ �� ������� �������
			Node<T>* current = head;
			while (i < index - 1) {
				current = current->next;
				++i;
			}
			//�������������� ������
			temp->next = current->next;
			current->next = temp;
		}
	}

	void Del(int index) {
		if (index < 0 || index >= size)
			std::cout << "Index is out of bound\n";
		else if (index == 0)
			DellFront();
		else if (index == size - 1)
			DellBack();
		else {

			--size;
			int i = 0;
			//���������� ������ �� ������� �������
			Node<T>* current = head;
			while (i < index - 1) {
				current = current->next;
				++i;
			}
			//�������������� ������
			Node<T>* temp = current->next;
			current->next = temp->next;
			delete temp;
		}

	}

	bool Contain(T data) const {
		Node<T>* tmp = head;
		while (tmp) {
			if (tmp->data == data)
				return true;
			tmp = tmp->next;
		}
		return false;
	}

	List<T> operator+(const List<T>& other) {
		List<T> result(*this);
		Node<T>* tmp = other.head;
		while (tmp) {
			result.AddBack(tmp->data);
			tmp = tmp->next;
		}
		return result;
	}

	List<T> operator*(const List<T>& other) {
		List<T> result;
		Node<T>* tmp = head;
		while (tmp) {
			if (other.Contain(tmp->data))
				result.AddBack(tmp->data);
			tmp = tmp->next;
		}
		return result;
	}
};
