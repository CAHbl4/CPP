#pragma once
#include <iostream>

//класс Список - совокупность узлов
template <class T>
class List {
	//количество элементов в списке
	int size;
	//указатель на начало списка
	Node<T>* head;
	//указатель на конец списка
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
		//увеличиваем размер списка
		++size;
		//создаем узел
		Node<T>* temp = new Node<T>;
		temp->data = data;
		temp->next = NULL;
		//если список пуст
		if (!head)
			head = tail = temp;
		//если список не пуст
		else {
			//последний элемент списка связываем с новым (temp)
			tail->next = temp;
			//перемещаем указатель конца на новый элемент
			tail = temp;
		}
	}

	void AddFront(T data) {
		//увеличиваем размер списка
		++size;
		//создаем узел
		Node<T>* temp = new Node<T>;
		temp->data = data;
		temp->next = NULL;
		//если список пуст
		if (!head)
			head = tail = temp;
		//если список не пуст
		else {
			//новый элемент списка связываем с первым
			temp->next = head;
			//перемещаем указатель начала на новый элемент
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

	//удаление элементов
	void DellBack() {
		Node<T>* temp = head;
		if (head) {
			--size;
			if (!head->next) {
				delete head;
				head = tail = NULL;
			}
			else {
				//пробегаем по списку до предпоследнего элемента
				while ((temp->next)->next)
					temp = temp->next;
				//удаляем последний элемент
				delete tail;
				//переносим tail на предпоследний
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

	//метод вывода списка
	void ShowList() const {
		std::cout << "Size:" << size << std::endl;
		//временный указатель для просмотра списка
		Node<T>* temp = head;
		while (temp) {
			//выводим данные
			std::cout << temp->data << "\t";
			//переходим к следующему элементу
			temp = temp->next;
		}
		std::cout << std::endl;
	}

	//вставка и удаление из произвольного места
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
			//определяем ссылку на текущий элемент
			Node<T>* current = head;
			while (i < index - 1) {
				current = current->next;
				++i;
			}
			//переопределяем ссылки
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
			//определяем ссылку на текущий элемент
			Node<T>* current = head;
			while (i < index - 1) {
				current = current->next;
				++i;
			}
			//переопределяем ссылки
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
