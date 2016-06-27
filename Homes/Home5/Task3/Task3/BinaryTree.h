#pragma once
#include <iostream>

//структура узла для бинарного дерева
template <class T>
struct NodeTree {
	//информационная часть
	T data;
	//ссылки на левого и правого потомков
	NodeTree<T>* left;
	NodeTree<T>* right;
	NodeTree<T>* root;
};

//класс бинарное дерево
template <class T>
class BinaryTree {
	//корень дерева
	NodeTree<T>* root;
public:
	BinaryTree() : root(nullptr) {}

	//метод поиска
	bool Search(T data) {
		NodeTree<T>* temp = root;
		while (temp) {
			//если элемент найден возвращаем true
			if (data == temp->data)
				return true;
			//если data< temp->data переходим в левое поддерево
			if (data < temp->data) {
				temp = temp->left;
			}
			//если data> temp->data переходим в правое поддерево
			else {
				temp = temp->right;
			}
		}
		return temp != nullptr;
	}

	//метод добавления элемента в дерево
	void Add(T data) {
		//если такой элемент уже есть
		if (Search(data))
		//выводим сообщение
			std::cout << "Same elemet already exist!!!\n";
		//такого элемента нет
		else {
			//создаем новый узел
			NodeTree<T>* newNode = new NodeTree<T>;
			newNode->data = data;
			newNode->left = nullptr;
			newNode->right = nullptr;
			newNode->root = nullptr;

			//если нет корня
			if (!root)
			//делаем созданный узел корнем дерева
				root = newNode;
			//корень есть (дерево уже растет)
			else {
				//создаем временный указатель на элемент
				//к которому подсоединяем созданный узел
				NodeTree<T>* temp = root;
				while (temp) {
					//определяем по какой ветке идти
					//если data< temp->data идем влево
					if (data < temp->data) {
						//проверяем есть ли левое поддерево (ветвь)
						if (temp->left)
						//если есть переходим влево
							temp = temp->left;
						else {
							//нашли куда подсоединяться
							newNode->root = temp;
							temp->left = newNode;
							break;
						}
					}
					//если data> temp->data идем вправо
					else {
						//проверяем есть ли правое поддерево (ветвь)
						if (temp->right)
						//если есть переходим вправо
							temp = temp->right;
						else {
							//нашли куда подсоединяться
							newNode->root = temp;
							temp->right = newNode;
							break;
						}
					}
				}
			}
		}
	}

	//рекурсивный метод вывода дерева
	void Show(NodeTree<T>* ptr, int level) {
		//условие вызова рекурсии
		if (ptr) {
			//рекурсивный проход вправо до конца
			//при каждом вызове уровень повышается
			Show(ptr->right, level + 1);
			//печатаем отступы
			for (int i = 0; i < level; i++)
				std::cout << "\t";
			//печатаем data
			std::cout << ptr->data << ":" << level << std::endl;
			//рекурсивный проход влево
			Show(ptr->left, level + 1);
		}
	}

	//метод получения указателя на root
	NodeTree<T>* GetRoot() const {
		return root;
	}

	T& Get(T data) {
		NodeTree<T>* temp = root;
		while (temp) {
			//если элемент найден возвращаем true
			if (data == temp->data)
				return temp->data;
			//если data< temp->data переходим в левое поддерево
			if (data < temp->data) {
				temp = temp->left;
			}
			//если data> temp->data переходим в правое поддерево
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

	//очистка содержимого дерева
	void Clear(NodeTree<T>* ptr) {
		if (ptr) {
			Clear(ptr->right);
			Clear(ptr->left);
			delete ptr;
		}
		//память очищена, но root еще указывает на определенную ячейку, поэтому зануляем
		root = nullptr;
	}

	//деструктор
	~BinaryTree() {
		//вызываем метод очистки
		Clear(root);
	}

	//удаление элементов
	void Delete(T data) {
		if (!Search(data))
			std::cout << "The tree have not node with this data!!!\n";
		else {
			//ищем удаляемый узел и запоминаем его предка
			//удаляемый узел
			NodeTree<T>* temp = root;
			//его предок
			NodeTree<T>* prev = nullptr;
			while (temp->data != data) {
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
			if (temp->left == nullptr && temp->right == nullptr) {
				//зануляем ссылку у предка, которая указывает на удаляемый лист
				if (prev->left == temp)
					prev->left = nullptr;
				else
					prev->right = nullptr;
				//удалем лист
				delete temp;
			}
			else
			//удаление узла с одной дочерней веткой
			if (temp->left == nullptr || temp->right == nullptr) {
				//у удаляемого узла есть левая ветвь
				if (temp->left) {
					//определяем в какой ветви находится удаляемый
					//узел относительно предка
					if (prev->left == temp)
					//подсоединяем ветвь с левой стороны
					{
						temp->left->root = prev;
						prev->left = temp->left;
					}
					else
					//подсоединяем ветвь с правой стороны
					{
						temp->left->root = prev;
						prev->right = temp->left;
					}
				}
				//у удаляемого узла есть правая ветвь
				else {
					//определяем в какой ветви находится удаляемый
					//узел относительно предка
					if (prev->left == temp)
					//подсоединяем ветвь с левой стороны
					{
						temp->right->root = prev;
						prev->left = temp->right;
					}
					else
					//подсоединяем ветвь с правой стороны
					{
						temp->right->root = prev;
						prev->right = temp->right;
					}

				}

			}
			//удаление узла с двумя дочерними ветками
			else {
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
				NodeTree<T>* connect = temp->right;
				//пробегаемся влево до конца
				while (connect->left)
					connect = connect->left;
				//подсоединяем левую ветвь удаляемого узла
				temp->left->root = connect;
				connect->left = temp->left;
				//подсоединяемся к родительскому узлу
				//проверяем является ли узел корнем
				if (prev == nullptr)
				//переносим корень в правую ветвь
					root = temp->right;
				//определяем в какой ветви находится удаляемый
				else {
					if (prev->left == temp)
					//подсоединяем правую (обновленную ветвь) к родителю
					{
						temp->right->root = prev;
						prev->left = temp->right;
					}
					else {
						temp->right->root = prev;
						prev->right = temp->right;
					}

				}
				//удаляем узел
				delete temp;
			}
		}
	}

};
