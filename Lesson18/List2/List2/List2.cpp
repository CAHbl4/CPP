// List2.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

//��������� ����
struct Node
{
	int data;
	//��������� �� ��������� ����
	Node* next;
	//��������� �� ����������
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
			//���������� ��������� �� ������ �������
			temp = head;
			// ��������� head �� ��������� �������
			head = head->next;
			//������� ������
			delete temp;
		}
	}
	void AddFront(int data)
	{
		//����������� ������
		++size;
		//������� ����� ����
		Node* newNode = new Node;
		newNode->data = data;
		newNode->next = NULL;
		newNode->prev = NULL;
		//��������� ���� �� �������� � ������
		if (!head)
			//���� ��� ��������� ���������� ��������� �� ����� ���������
			head = tail = newNode;
		else
		{
			//��������� � ������, ������� ���������
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		}
	}
	//������� �������� � ����� ������
	void AddBack(int data)
	{
		//����������� ������
		++size;
		//������� ����� ����
		Node* newNode = new Node;
		newNode->data = data;
		newNode->next = NULL;
		newNode->prev = NULL;
		//��������� ���� �� �������� � ������
		if (!head)
			//���� ��� ��������� ���������� ��������� �� ����� ���������
			head = tail = newNode;
		else
		{
			//��������� � �����, ������� ���������
			newNode->prev = tail;
			tail->next = newNode;
			tail = newNode;
		}

	}

	//����������� ������� Print
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
		//����� � �������������� ��������
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
		//����������� ������
		++size;
		//������� ����� ����
		Node* newNode = new Node;
		newNode->data = data;
		newNode->next = NULL;
		newNode->prev = NULL;
		//��������� ���� �� �������� � ������
		if (!head)
			//���� ��� ��������� ���������� ��������� �� ����� ���������
			head = tail = newNode;
		else
		{
			//�������� �������� ��� ������� � ������ ������
			//temp - ��������� �� ������� � ������� data
			Node* temp = head;
			//����������� �� ������ ���� �� ������ ������� � ������� data
			while (temp&&data > temp->data)
				temp=temp->next;

			//3 ��������: 1- temp ��������� �� ������ �������
			if (temp == head)
			{
				delete newNode;
				AddFront(data);
			}
			else
				//2- temp ��������� �� ������� � ������
			if (temp)
			{
				//��������� ����� ������� � ������ �������, ������������ �����
				newNode->next = temp;
				newNode->prev = temp->prev;
				temp->prev = newNode;
				(newNode->prev)->next = newNode;
			}
			//3 - temp=NULL - ��� ��������� ������� ���������
			else
			{
				delete newNode;
				//��������� � ����� ������
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

