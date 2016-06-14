#include <iostream>
using namespace std;

//�������� ��������� ���� (������� ������)
struct Node
{
	//������
	int data;
	//��������� �� ��������� ���� (�������)
	Node* next;
};

//����� ������ - ������������ �����
class List
{
	//���������� ��������� � ������
	int size;
	//��������� �� ������ ������
	Node* head;
	//��������� �� ����� ������
	Node* tail;
public:
	List() :size(0), head(NULL),tail(NULL) {}
	void AddBack(int data)
	{
		//����������� ������ ������
		++size;
		//������� ����
		Node* temp = new Node;
		temp->data = data;
		temp->next = NULL;
		//���� ������ ����
		if (!head)
			head =tail=temp;
		//���� ������ �� ����
		else
		{
			//��������� ������� ������ ��������� � ����� (temp)
			tail->next = temp;
			//���������� ��������� ����� �� ����� �������
			tail = temp;
		}
	}

	void AddFront(int data)
	{
		//����������� ������ ������
		++size;
		//������� ����
		Node* temp = new Node;
		temp->data = data;
		temp->next = NULL;
		//���� ������ ����
		if (!head)
			head = tail = temp;
		//���� ������ �� ����
		else
		{
			//����� ������� ������ ��������� � ������
			temp->next = head;
			//���������� ��������� ������ �� ����� �������
			head = temp;
		}
		
	}
	~List()
	{
		Node* temp;
		while (head)
		{
			//���������� ����� ������� ��������
			temp = head;
			//��������� ��������� ������ ������ �� ��������� �������
			head = temp->next;
			//������� ������ �������
			delete temp;
		}
		cout << "Destructor!!!\n";
	}
	//�������� ���������
	void DellBack()
	{
		Node* temp = head;
		if (head)
		{
			--size;
			if (!head->next)
			{
				delete head;
				head = tail = NULL;
			}
			else
			{
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

	void DellFront()
	{
		
		Node* temp=head;
		if (head)
		{
			--size;
			head = head->next;
			delete temp;
		}
	}

	//����� ������ ������
	void ShowList()
	{
		cout << "Size:" << size << endl;
		//��������� ��������� ��� ��������� ������
		Node* temp=head;
		while (temp)
		{
			//������� ������
			cout << temp->data << "\t";
			//��������� � ���������� ��������
			temp = temp->next;
		}
		cout << endl;
	}

	//������� � �������� �� ������������� �����
	void Add(int index,int data)
	{
		if (index<0 || index>=size)
			cout << "Index is out of bound\n";
		else
		if (index == 0)
			AddFront(data);
		else
		if (index == size-1)
			AddBack(data);
		else
		{
			++size;
			Node* temp = new Node;
			temp->data = data;
			int i = 0;
			//���������� ������ �� ������� �������
			Node* current=head;
			while (i < index-1)
			{
				current = current->next;
				++i;
			}
			//�������������� ������
			temp->next = current->next;
			current->next = temp;
		}
	}

	void Del(int index)
	{
		if (index<0 || index >= size)
			cout << "Index is out of bound\n";
		else
		if (index == 0)
			DellFront();
		else
		if (index == size - 1)
			DellBack();
		else
		{

			--size;
			int i = 0;
			//���������� ������ �� ������� �������
			Node* current = head;
			while (i < index - 1)
			{
				current = current->next;
				++i;
			}
			//�������������� ������
			Node* temp = current->next;
			current->next = temp->next;
			delete temp;
		}


	}
};


int main()
{
	//��� ��� �������
	//int *ptr;
	//cout << "Enter size:";
	//int size;
	//cin >> size;
	//ptr = new int[size];
	//for (int i = 0; i < size; i++)
	//	ptr[i] = rand() % 100;
	//for (int i = 0; i < size; i++)
	//	cout<<ptr[i]<<"\t";
	//cout << endl;
	////�������� �������� � �������� �������
	//int *temp = new int[size + 1];
	//cout << "Enter data for add:";
	//int data;
	//cin >> data;
	////������ �������� ��������
	//int half=size/2;
	////�������� ������ ��������
	//for (int i = 0; i < half; i++)
	//	temp[i] = ptr[i];
	////��������� �������
	//temp[half] = data;
	////�������� ���������� ��������
	//for (int i = half; i < size; i++)
	//	temp[i + 1] = ptr[i];
	//delete[] ptr;
	//ptr = temp;
	//temp = NULL;
	//++size;
	//for (int i = 0; i < size; i++)
	//	cout << ptr[i] << "\t";
	//cout << endl;

	{
		List l1;
		
		l1.AddBack(7);
		l1.AddFront(1);
		
		l1.ShowList();
		l1.Add(0, 10);
		l1.ShowList();
		l1.Add(2,20);
		l1.ShowList();
		l1.Add(1, 30);
		l1.ShowList();
		l1.Add(10, 33);
		l1.ShowList();
		l1.Del(1);
		l1.ShowList();
		l1.Del(0);
		l1.ShowList();
		l1.Del(1);
		l1.ShowList();
		
	}


	
	system("pause");
	return 0;
}