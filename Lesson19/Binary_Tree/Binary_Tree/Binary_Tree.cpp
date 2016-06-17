// Binary_Tree.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

//рекурсивная функция вычисления n!
int fuctorial(int n)
{
	cout << "n=" << n << ", adress=" << &n << endl;
	if (n == 0 || n == 1)
		return 1;
	else
		return n*fuctorial(n - 1);
};

//структура узла для бинарного дерева
struct Node
{
	//информационная часть
	int data;
	//ссылки на левого и правого потомков
	Node* left;
	Node* right;
};


//класс бинарное дерево
class Tree
{
	//корень дерева
	Node* root;
public:
	Tree() :root(NULL){}
	//метод поиска
	bool Search(int data)
	{
		Node* temp = root;
		while (temp)
		{
			//если элемент найден возвращаем true
			if (data == temp->data)
				return true;
			//если data< temp->data переходим в левое поддерево
			if (data < temp->data)
			{
				temp = temp->left;
			}
			//если data> temp->data переходим в правое поддерево
			else 
			{
				temp = temp->right;
			}
		}
		return temp;
	}
	//метод добавления элемента в дерево
	void Add(int data)
	{
		//если такой элемент уже есть
		if (Search(data))
			//выводим сообщение
			cout << "Same elemet already exist!!!\n";
		//такого элемента нет
		else
		{
			//создаем новый узел
			Node* newNode = new Node;
			newNode->data = data;
			newNode->left = NULL;
			newNode->right = NULL;

			//если нет корня
			if (!root)
				//делаем созданный узел корнем дерева
				root = newNode;
			//корень есть (дерево уже растет)
			else
			{
				//создаем временный указатель на элемент
				//к которому подсоединяем созданный узел
				Node* temp = root;
				while (temp)
				{
					//определяем по какой ветке идти
					//если data< temp->data идем влево
					if (data < temp->data)
					{
						//проверяем есть ли левое поддерево (ветвь)
						if (temp->left)
							//если есть переходим влево
							temp = temp->left;
						else
						{
							//нашли куда подсоединяться
							temp->left = newNode;
							break;
						}
					}
					//если data> temp->data идем вправо
					else
					{
						//проверяем есть ли правое поддерево (ветвь)
						if (temp->right)
							//если есть переходим вправо
							temp = temp->right;
						else
						{
							//нашли куда подсоединяться
							temp->right = newNode;
							break;
						}
					}
				}
			}
		}
	}

	//рекурсивный метод вывода дерева
	void Show(Node* ptr,int level)
	{
		//условие вызова рекурсии
		if (ptr)
		{
			//рекурсивный проход вправо до конца
			//при каждом вызове уровень повышается
			Show(ptr->right,level+1);
			//печатаем отступы
			for (int i = 0; i < level; i++)
				cout << "\t";
			//печатаем data
			cout << ptr->data <<":"<<level<< endl;
			//рекурсивный проход влево
			Show(ptr->left,level+1);
		}
	}
	//метод получения указателя на root
	Node* GetRoot() const
	{
		return root;
	}

	//очистка содержимого дерева
	void Clear(Node* ptr)
	{
		if (ptr)
		{
			Clear(ptr->right);
			Clear(ptr->left);
			cout << "Delete data:" << ptr->data << endl;
			delete ptr;
		}
		//память очищена, но root еще указывает на определенную ячейку, поэтому зануляем
		root = NULL;
	}
	//деструктор
	~Tree()
	{
		//вызываем метод очистки
		Clear(root);
	}
	//удаление элементов
	void Delete(int data)
	{
		if (!Search(data))
			cout << "The tree have not node with this data!!!\n";
		else
		{
			//ищем удаляемый узел и запоминаем его предка
			//удаляемый узел
			Node *temp = root;
			//его предок
			Node *prev = NULL;
			while (temp->data != data)
			{
				//запоминаем предка
				prev = temp;
				//перещаемся вниз по дереву
				//елси data < temp->data идем по левой ветке
				if (data < temp->data)
					temp = temp->left;
				else
					//иначе идем по правой ветке
					temp = temp->right;
			}
			//удаление узла
			//удаление если лист
			if (temp->left == NULL&&temp->right == NULL)
			{
				//зануляем ссылку у предка, которая указывает на удаляемый лист
				if (prev->left == temp)
					prev->left = NULL;
				else
					prev->right = NULL;
				//удалем лист
				delete temp;
			}
			else
			//удаление узла с одной дочерней веткой
			if (temp->left == NULL || temp->right == NULL)
			{
				//у удаляемого узла есть левая ветвь
				if (temp->left)
				{
					//определяем в какой ветви находится удаляемый
					//узел относительно предка
					if (prev->left == temp)
						//подсоединяем ветвь с левой стороны
						prev->left = temp->left;
					else
						//подсоединяем ветвь с правой стороны
						prev->right = temp->left;
				}
				//у удаляемого узла есть правая ветвь
				else
				{
					//определяем в какой ветви находится удаляемый
					//узел относительно предка
					if (prev->left == temp)
						//подсоединяем ветвь с левой стороны
						prev->left = temp->right;
					else
						//подсоединяем ветвь с правой стороны
						prev->right = temp->right;

				}

			}
			//удаление узла с двумя дочерними ветками
			else
			{
				////переходим к левой ветке
				//Node* connect = temp->left;
				////пробегаемся вправо до конца
				//while (connect->right)
				//	connect = connect->right;
				////подсоединяем правую ветвь удаляемого узла
				//connect->right = temp->right;
				////подсоединяемся к родительскому узлу
				////проверяем является ли узел корнем
				//if (prev == NULL)
				//	//переносим корень в левую ветвь
				//	root = temp->left;
				////определяем в какой ветви находится удаляемый
				//else
				//{
				//	if (prev->left == temp)
				//		//подсоединяем левую (обновленную ветвь) к родителю
				//		prev->left = temp->left;
				//	else
				//		prev->right = temp->left;
				//	//проверяем является ли узел корнем
				//	if (prev == NULL)
				//		//переносим корень в левую ветвь
				//		root = temp->left;

				//переходим к правой ветке
				Node* connect = temp->right;
				//пробегаемся влево до конца
				while (connect->left)
					connect = connect->left;
				//подсоединяем левую ветвь удаляемого узла
				connect->left = temp->left;
				//подсоединяемся к родительскому узлу
				//проверяем является ли узел корнем
				if (prev == NULL)
					//переносим корень в правую ветвь
					root = temp->right;
				//определяем в какой ветви находится удаляемый
				else
				{
					if (prev->left == temp)
						//подсоединяем правую (обновленную ветвь) к родителю
						prev->left = temp->right;
					else
						prev->right = temp->right;
					
				}
				//удаляем узел
				delete temp;
			}
		}
	}

};

int _tmain(int argc, _TCHAR* argv[])
{
	////вспомним о рекурсии
	//int n;
	//cout << "Enter n:";
	//cin >> n;
	//cout << "n!=" << fuctorial(n) << endl;
	//system("pause");
	//system("cls");
	//работа с деревом
	Tree tr1;
	tr1.Add(50);
	tr1.Add(80);
	tr1.Add(30);
	tr1.Add(40);
	tr1.Add(70);
	tr1.Add(10);
	tr1.Add(75);
	tr1.Add(100);
	//попытка добавить уже существующий элемент
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

