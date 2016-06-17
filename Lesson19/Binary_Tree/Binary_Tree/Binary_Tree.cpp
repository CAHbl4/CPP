// Binary_Tree.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

//����������� ������� ���������� n!
int fuctorial(int n)
{
	cout << "n=" << n << ", adress=" << &n << endl;
	if (n == 0 || n == 1)
		return 1;
	else
		return n*fuctorial(n - 1);
};

//��������� ���� ��� ��������� ������
struct Node
{
	//�������������� �����
	int data;
	//������ �� ������ � ������� ��������
	Node* left;
	Node* right;
};


//����� �������� ������
class Tree
{
	//������ ������
	Node* root;
public:
	Tree() :root(NULL){}
	//����� ������
	bool Search(int data)
	{
		Node* temp = root;
		while (temp)
		{
			//���� ������� ������ ���������� true
			if (data == temp->data)
				return true;
			//���� data< temp->data ��������� � ����� ���������
			if (data < temp->data)
			{
				temp = temp->left;
			}
			//���� data> temp->data ��������� � ������ ���������
			else 
			{
				temp = temp->right;
			}
		}
		return temp;
	}
	//����� ���������� �������� � ������
	void Add(int data)
	{
		//���� ����� ������� ��� ����
		if (Search(data))
			//������� ���������
			cout << "Same elemet already exist!!!\n";
		//������ �������� ���
		else
		{
			//������� ����� ����
			Node* newNode = new Node;
			newNode->data = data;
			newNode->left = NULL;
			newNode->right = NULL;

			//���� ��� �����
			if (!root)
				//������ ��������� ���� ������ ������
				root = newNode;
			//������ ���� (������ ��� ������)
			else
			{
				//������� ��������� ��������� �� �������
				//� �������� ������������ ��������� ����
				Node* temp = root;
				while (temp)
				{
					//���������� �� ����� ����� ����
					//���� data< temp->data ���� �����
					if (data < temp->data)
					{
						//��������� ���� �� ����� ��������� (�����)
						if (temp->left)
							//���� ���� ��������� �����
							temp = temp->left;
						else
						{
							//����� ���� ��������������
							temp->left = newNode;
							break;
						}
					}
					//���� data> temp->data ���� ������
					else
					{
						//��������� ���� �� ������ ��������� (�����)
						if (temp->right)
							//���� ���� ��������� ������
							temp = temp->right;
						else
						{
							//����� ���� ��������������
							temp->right = newNode;
							break;
						}
					}
				}
			}
		}
	}

	//����������� ����� ������ ������
	void Show(Node* ptr,int level)
	{
		//������� ������ ��������
		if (ptr)
		{
			//����������� ������ ������ �� �����
			//��� ������ ������ ������� ����������
			Show(ptr->right,level+1);
			//�������� �������
			for (int i = 0; i < level; i++)
				cout << "\t";
			//�������� data
			cout << ptr->data <<":"<<level<< endl;
			//����������� ������ �����
			Show(ptr->left,level+1);
		}
	}
	//����� ��������� ��������� �� root
	Node* GetRoot() const
	{
		return root;
	}

	//������� ����������� ������
	void Clear(Node* ptr)
	{
		if (ptr)
		{
			Clear(ptr->right);
			Clear(ptr->left);
			cout << "Delete data:" << ptr->data << endl;
			delete ptr;
		}
		//������ �������, �� root ��� ��������� �� ������������ ������, ������� ��������
		root = NULL;
	}
	//����������
	~Tree()
	{
		//�������� ����� �������
		Clear(root);
	}
	//�������� ���������
	void Delete(int data)
	{
		if (!Search(data))
			cout << "The tree have not node with this data!!!\n";
		else
		{
			//���� ��������� ���� � ���������� ��� ������
			//��������� ����
			Node *temp = root;
			//��� ������
			Node *prev = NULL;
			while (temp->data != data)
			{
				//���������� ������
				prev = temp;
				//���������� ���� �� ������
				//���� data < temp->data ���� �� ����� �����
				if (data < temp->data)
					temp = temp->left;
				else
					//����� ���� �� ������ �����
					temp = temp->right;
			}
			//�������� ����
			//�������� ���� ����
			if (temp->left == NULL&&temp->right == NULL)
			{
				//�������� ������ � ������, ������� ��������� �� ��������� ����
				if (prev->left == temp)
					prev->left = NULL;
				else
					prev->right = NULL;
				//������ ����
				delete temp;
			}
			else
			//�������� ���� � ����� �������� ������
			if (temp->left == NULL || temp->right == NULL)
			{
				//� ���������� ���� ���� ����� �����
				if (temp->left)
				{
					//���������� � ����� ����� ��������� ���������
					//���� ������������ ������
					if (prev->left == temp)
						//������������ ����� � ����� �������
						prev->left = temp->left;
					else
						//������������ ����� � ������ �������
						prev->right = temp->left;
				}
				//� ���������� ���� ���� ������ �����
				else
				{
					//���������� � ����� ����� ��������� ���������
					//���� ������������ ������
					if (prev->left == temp)
						//������������ ����� � ����� �������
						prev->left = temp->right;
					else
						//������������ ����� � ������ �������
						prev->right = temp->right;

				}

			}
			//�������� ���� � ����� ��������� �������
			else
			{
				////��������� � ����� �����
				//Node* connect = temp->left;
				////����������� ������ �� �����
				//while (connect->right)
				//	connect = connect->right;
				////������������ ������ ����� ���������� ����
				//connect->right = temp->right;
				////�������������� � ������������� ����
				////��������� �������� �� ���� ������
				//if (prev == NULL)
				//	//��������� ������ � ����� �����
				//	root = temp->left;
				////���������� � ����� ����� ��������� ���������
				//else
				//{
				//	if (prev->left == temp)
				//		//������������ ����� (����������� �����) � ��������
				//		prev->left = temp->left;
				//	else
				//		prev->right = temp->left;
				//	//��������� �������� �� ���� ������
				//	if (prev == NULL)
				//		//��������� ������ � ����� �����
				//		root = temp->left;

				//��������� � ������ �����
				Node* connect = temp->right;
				//����������� ����� �� �����
				while (connect->left)
					connect = connect->left;
				//������������ ����� ����� ���������� ����
				connect->left = temp->left;
				//�������������� � ������������� ����
				//��������� �������� �� ���� ������
				if (prev == NULL)
					//��������� ������ � ������ �����
					root = temp->right;
				//���������� � ����� ����� ��������� ���������
				else
				{
					if (prev->left == temp)
						//������������ ������ (����������� �����) � ��������
						prev->left = temp->right;
					else
						prev->right = temp->right;
					
				}
				//������� ����
				delete temp;
			}
		}
	}

};

int _tmain(int argc, _TCHAR* argv[])
{
	////�������� � ��������
	//int n;
	//cout << "Enter n:";
	//cin >> n;
	//cout << "n!=" << fuctorial(n) << endl;
	//system("pause");
	//system("cls");
	//������ � �������
	Tree tr1;
	tr1.Add(50);
	tr1.Add(80);
	tr1.Add(30);
	tr1.Add(40);
	tr1.Add(70);
	tr1.Add(10);
	tr1.Add(75);
	tr1.Add(100);
	//������� �������� ��� ������������ �������
	tr1.Add(40);
	tr1.Show(tr1.GetRoot(),0);
	if(tr1.Search(23))
		cout<<"Element exist\n";
	else
		cout << "Elemet not exist!!!\n";
	tr1.Delete(80);
	tr1.Show(tr1.GetRoot(), 0);


	system("pause");
	return 0;
}

