#include <iostream>
using namespace std;

//описание структуры узла (элемент списка)
struct Node
{
	//данные
	int data;
	//указатель на следующий узел (элемент)
	Node* next;
};

//класс Список - совокупность узлов
class List
{
	//количество элементов в списке
	int size;
	//указатель на начало списка
	Node* head;
	//указатель на конец списка
	Node* tail;
public:
	List() :size(0), head(NULL),tail(NULL) {}
	void AddBack(int data)
	{
		//увеличиваем размер списка
		++size;
		//создаем узел
		Node* temp = new Node;
		temp->data = data;
		temp->next = NULL;
		//если список пуст
		if (!head)
			head =tail=temp;
		//если список не пуст
		else
		{
			//последний элемент списка связываем с новым (temp)
			tail->next = temp;
			//перемещаем указатель конца на новый элемент
			tail = temp;
		}
	}

	void AddFront(int data)
	{
		//увеличиваем размер списка
		++size;
		//создаем узел
		Node* temp = new Node;
		temp->data = data;
		temp->next = NULL;
		//если список пуст
		if (!head)
			head = tail = temp;
		//если список не пуст
		else
		{
			//новый элемент списка связываем с первым
			temp->next = head;
			//перемещаем указатель начала на новый элемент
			head = temp;
		}
		
	}
	~List()
	{
		Node* temp;
		while (head)
		{
			//запоминаем адрес первого элемента
			temp = head;
			//переносим указатель начала списка на следующий элемент
			head = temp->next;
			//удаляем первый элемент
			delete temp;
		}
		cout << "Destructor!!!\n";
	}
	//удаление элементов
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

	//метод вывода списка
	void ShowList()
	{
		cout << "Size:" << size << endl;
		//временный указатель для просмотра списка
		Node* temp=head;
		while (temp)
		{
			//выводим данные
			cout << temp->data << "\t";
			//переходим к следующему элементу
			temp = temp->next;
		}
		cout << endl;
	}

	//вставка и удаление из произвольного места
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
			//определяем ссылку на текущий элемент
			Node* current=head;
			while (i < index-1)
			{
				current = current->next;
				++i;
			}
			//переопределяем ссылки
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
			//определяем ссылку на текущий элемент
			Node* current = head;
			while (i < index - 1)
			{
				current = current->next;
				++i;
			}
			//переопределяем ссылки
			Node* temp = current->next;
			current->next = temp->next;
			delete temp;
		}


	}
};


int main()
{
	//Это для примера
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
	////втставка элемента в середину массива
	//int *temp = new int[size + 1];
	//cout << "Enter data for add:";
	//int data;
	//cin >> data;
	////индекс среднего элемента
	//int half=size/2;
	////копируем первую половину
	//for (int i = 0; i < half; i++)
	//	temp[i] = ptr[i];
	////вставляем элемент
	//temp[half] = data;
	////копируем оставшуюся половину
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