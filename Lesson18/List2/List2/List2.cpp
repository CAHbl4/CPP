// List2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

//структура узла
struct Node
{
	int data;
	//указатель на следующий узел
	Node* next;
	//указатель на предыдущий
	Node* prev;
};

class List2
{
	int size;
	Node* head;
	Node* tail;
public:
	List2() :size(0), head(NULL), tail(NULL){}
	~List2()
	{
		Node* temp;
		while (head)
		{
			//запоминаем указатель на первый элемент
			temp = head;
			// переносим head на следующий элемент
			head = head->next;
			//удаляем первый
			delete temp;
		}
	}
	void AddFront(int data)
	{
		//увеличиваем размер
		++size;
		//создаем новый узел
		Node* newNode = new Node;
		newNode->data = data;
		newNode->next = NULL;
		newNode->prev = NULL;
		//проверяем есть ли элементы в списке
		if (!head)
			//если нет элементов перемещаем указатели на вновь созданный
			head = tail = newNode;
		else
		{
			//добавляем в начало, изменяя указатели
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		}
	}
	//вставка элемента в конец списка
	void AddBack(int data)
	{
		//увеличиваем размер
		++size;
		//создаем новый узел
		Node* newNode = new Node;
		newNode->data = data;
		newNode->next = NULL;
		newNode->prev = NULL;
		//проверяем есть ли элементы в списке
		if (!head)
			//если нет элементов перемещаем указатели на вновь созданный
			head = tail = newNode;
		else
		{
			//добавляем в конец, изменяя указатели
			newNode->prev = tail;
			tail->next = newNode;
			tail = newNode;
		}

	}

	//рекурсивная функция Print
	void Print(Node* ptr)
	{
		if (ptr)
		{
			cout << ptr->data << "\t";
			Print(ptr->next);
		}
	}

	void Show()
	{
		//вывод с использованием рекурсии
		Print(head);
		cout << endl;
	}
	void ClearAll()
	{
		Clear(head);
		head = tail = NULL;
	}

	void Clear(Node* ptr)
	{
		if (ptr)
		{
			--size;
			Clear(ptr->next);
			delete ptr;
		}
	}
	void Add(int data)
	{
		//увеличиваем размер
		++size;
		//создаем новый узел
		Node* newNode = new Node;
		newNode->data = data;
		newNode->next = NULL;
		newNode->prev = NULL;
		//проверяем есть ли элементы в списке
		if (!head)
			//если нет элементов перемещаем указатели на вновь созданный
			head = tail = newNode;
		else
		{
			//начинаем просмотр для вставки с начала списка
			//temp - указатель на элемент с большим data
			Node* temp = head;
			//пробегаемся по списку пока не найдем элемент с большим data
			while (temp&&data > temp->data)
				temp=temp->next;

			//3 варианта: 1- temp указывает на первый элемент
			if (temp == head)
			{
				delete newNode;
				AddFront(data);
			}
			else
				//2- temp указывает на элемент в списке
			if (temp)
			{
				//вставляем новый элемент в нужную позицию, устанавливая связи
				newNode->next = temp;
				newNode->prev = temp->prev;
				temp->prev = newNode;
				(newNode->prev)->next = newNode;
			}
			//3 - temp=NULL - нет элементов больших вводимого
			else
			{
				delete newNode;
				//вставляем в конец списка
				AddBack(data);
			}
		}

	}

};


int _tmain(int argc, _TCHAR* argv[])
{
	List2 l2;
	l2.AddFront(1);
	l2.AddFront(2);
	l2.AddFront(3);
	l2.AddBack(1);
	l2.AddBack(2);
	l2.AddBack(3);
	l2.Show();
	l2.ClearAll();
	l2.Show();
	l2.Add(10);
	l2.Add(20);
	l2.Add(5);
	l2.Add(15);
	l2.Add(2);
	l2.Add(25);
	l2.Add(5);
	l2.Show();






	system("pause");
	return 0;
}

