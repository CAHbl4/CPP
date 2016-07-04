#include<iostream>
using namespace std;

class Data
{
protected:
	int data;
public:
	explicit Data(int data = 0) :data(data){}
	virtual void ShowData()
	{
		cout << "Data=" << data << endl;
	}
	//преобразование к задданному типу
	operator char()
	{
		return data;
	}
};

class DataNew : public Data
{
	int dataNew;
public:
	DataNew(int a, int b) :Data(a), dataNew(b){}
	void ShowData()
	{
		Data::ShowData();
		cout << "DataNew=" << dataNew << endl;
	}
};


int main()
{
	Data obj1(7);
	obj1.ShowData();

	//неявное преобразования int->Data
	//компилятор использует конструктор с одним параметром
	//если хотим запретить преобразование используем explicit в конструкторе
	Data obj2 = static_cast<Data>(5);
	obj2.ShowData();
	cout << obj2.operator char() << endl;
	cout << char('2' + obj2) << endl;
	
	//Преобразования в стиле С++
	char a = 'A';
	cout << "char=" << a << ", int=" << static_cast<int>(a);
	cout << ", double=" << static_cast<double>(a) << endl;

	//преобразование указателей
	Data* ptr1 = new Data(10);
	DataNew* ptr2 = new DataNew(50, 60);
	ptr1->ShowData();
	ptr2->ShowData();
	cout << "-------------------------------------\n";
	Data* ptr3;
	ptr3 = ptr1;
	ptr3->ShowData();
	ptr3 = ptr2;
	ptr3->ShowData();
	cout << "-------------------------------------\n";
	DataNew* ptr4;
	ptr4 = static_cast<DataNew*>(ptr1);
	//ptr4 = ptr1;
	ptr4->ShowData();
	ptr4 = ptr2;
	ptr4->ShowData();


	system("pause");
	return 0;
}