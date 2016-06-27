#pragma once
#include <iostream>

//��������� ���� ��� ��������� ������
template <class T>
struct NodeTree {
	//�������������� �����
	T data;
	//������ �� ������ � ������� ��������
	NodeTree<T>* left;
	NodeTree<T>* right;
	NodeTree<T>* root;
};

//����� �������� ������
template <class T>
class BinaryTree {
	//������ ������
	NodeTree<T>* root;
public:
	BinaryTree() : root(nullptr) {}

	//����� ������
	bool Search(T data) {
		NodeTree<T>* temp = root;
		while (temp) {
			//���� ������� ������ ���������� true
			if (data == temp->data)
				return true;
			//���� data< temp->data ��������� � ����� ���������
			if (data < temp->data) {
				temp = temp->left;
			}
			//���� data> temp->data ��������� � ������ ���������
			else {
				temp = temp->right;
			}
		}
		return temp != nullptr;
	}

	//����� ���������� �������� � ������
	void Add(T data) {
		//���� ����� ������� ��� ����
		if (Search(data))
		//������� ���������
			std::cout << "Same elemet already exist!!!\n";
		//������ �������� ���
		else {
			//������� ����� ����
			NodeTree<T>* newNode = new NodeTree<T>;
			newNode->data = data;
			newNode->left = nullptr;
			newNode->right = nullptr;
			newNode->root = nullptr;

			//���� ��� �����
			if (!root)
			//������ ��������� ���� ������ ������
				root = newNode;
			//������ ���� (������ ��� ������)
			else {
				//������� ��������� ��������� �� �������
				//� �������� ������������ ��������� ����
				NodeTree<T>* temp = root;
				while (temp) {
					//���������� �� ����� ����� ����
					//���� data< temp->data ���� �����
					if (data < temp->data) {
						//��������� ���� �� ����� ��������� (�����)
						if (temp->left)
						//���� ���� ��������� �����
							temp = temp->left;
						else {
							//����� ���� ��������������
							newNode->root = temp;
							temp->left = newNode;
							break;
						}
					}
					//���� data> temp->data ���� ������
					else {
						//��������� ���� �� ������ ��������� (�����)
						if (temp->right)
						//���� ���� ��������� ������
							temp = temp->right;
						else {
							//����� ���� ��������������
							newNode->root = temp;
							temp->right = newNode;
							break;
						}
					}
				}
			}
		}
	}

	//����������� ����� ������ ������
	void Show(NodeTree<T>* ptr, int level) {
		//������� ������ ��������
		if (ptr) {
			//����������� ������ ������ �� �����
			//��� ������ ������ ������� ����������
			Show(ptr->right, level + 1);
			//�������� �������
			for (int i = 0; i < level; i++)
				std::cout << "\t";
			//�������� data
			std::cout << ptr->data << ":" << level << std::endl;
			//����������� ������ �����
			Show(ptr->left, level + 1);
		}
	}

	//����� ��������� ��������� �� root
	NodeTree<T>* GetRoot() const {
		return root;
	}

	T& Get(T data) {
		NodeTree<T>* temp = root;
		while (temp) {
			//���� ������� ������ ���������� true
			if (data == temp->data)
				return temp->data;
			//���� data< temp->data ��������� � ����� ���������
			if (data < temp->data) {
				temp = temp->left;
			}
			//���� data> temp->data ��������� � ������ ���������
			else {
				temp = temp->right;
			}
		}
		return temp->data;
	}

	LinkedList<T> GetData() const {
		LinkedList<T> list;
		NodeTree<T>* temp = root;
		NodeTree<T>* right = root;
		while (right->right) {
			right = right->right;
		}

		while (temp->left)
			temp = temp->left;
		list.Add(temp->data);

		while (right->data != list[list.GetUpperBound()]) {
			while (temp->left && temp->left->data > list[list.GetUpperBound()])
				temp = temp->left;
			if (temp->data > list[list.GetUpperBound()])
				list.Add(temp->data);
			if (temp->right && temp->right->data > list[list.GetUpperBound()])
				temp = temp->right;
			else {
				temp = temp->root;
			}
		}
		return list;
	}

	//������� ����������� ������
	void Clear(NodeTree<T>* ptr) {
		if (ptr) {
			Clear(ptr->right);
			Clear(ptr->left);
			delete ptr;
		}
		//������ �������, �� root ��� ��������� �� ������������ ������, ������� ��������
		root = nullptr;
	}

	//����������
	~BinaryTree() {
		//�������� ����� �������
		Clear(root);
	}

	//�������� ���������
	void Delete(T data) {
		if (!Search(data))
			std::cout << "The tree have not node with this data!!!\n";
		else {
			//���� ��������� ���� � ���������� ��� ������
			//��������� ����
			NodeTree<T>* temp = root;
			//��� ������
			NodeTree<T>* prev = nullptr;
			while (temp->data != data) {
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
			if (temp->left == nullptr && temp->right == nullptr) {
				//�������� ������ � ������, ������� ��������� �� ��������� ����
				if (prev->left == temp)
					prev->left = nullptr;
				else
					prev->right = nullptr;
				//������ ����
				delete temp;
			}
			else
			//�������� ���� � ����� �������� ������
			if (temp->left == nullptr || temp->right == nullptr) {
				//� ���������� ���� ���� ����� �����
				if (temp->left) {
					//���������� � ����� ����� ��������� ���������
					//���� ������������ ������
					if (prev->left == temp)
					//������������ ����� � ����� �������
					{
						temp->left->root = prev;
						prev->left = temp->left;
					}
					else
					//������������ ����� � ������ �������
					{
						temp->left->root = prev;
						prev->right = temp->left;
					}
				}
				//� ���������� ���� ���� ������ �����
				else {
					//���������� � ����� ����� ��������� ���������
					//���� ������������ ������
					if (prev->left == temp)
					//������������ ����� � ����� �������
					{
						temp->right->root = prev;
						prev->left = temp->right;
					}
					else
					//������������ ����� � ������ �������
					{
						temp->right->root = prev;
						prev->right = temp->right;
					}

				}

			}
			//�������� ���� � ����� ��������� �������
			else {
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
				NodeTree<T>* connect = temp->right;
				//����������� ����� �� �����
				while (connect->left)
					connect = connect->left;
				//������������ ����� ����� ���������� ����
				temp->left->root = connect;
				connect->left = temp->left;
				//�������������� � ������������� ����
				//��������� �������� �� ���� ������
				if (prev == nullptr)
				//��������� ������ � ������ �����
					root = temp->right;
				//���������� � ����� ����� ��������� ���������
				else {
					if (prev->left == temp)
					//������������ ������ (����������� �����) � ��������
					{
						temp->right->root = prev;
						prev->left = temp->right;
					}
					else {
						temp->right->root = prev;
						prev->right = temp->right;
					}

				}
				//������� ����
				delete temp;
			}
		}
	}

};
