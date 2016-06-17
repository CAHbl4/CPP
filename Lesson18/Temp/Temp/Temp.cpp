// Novitskaya_home_7-1_Overcoat.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
class Overcoat
{
	char* type;
	char* model;
	float price;
	static int count;
public:
	Overcoat(char* typ = "0", char* mod = "0", float pr = 0) :price(pr)
	{
		type = new char[strlen(typ) + 1];
		strcpy_s(type, strlen(typ) + 1, typ);
		model = new char[strlen(mod) + 1];
		strcpy_s(model, strlen(mod) + 1, mod);
		Increment();
	}
	void SetOvercoat()
	{
		char str[256];
		cout << "Enter type of overcoat ";
		cin.getline(str, 256);
		type = new char[strlen(str) + 1];
		strcpy_s(type, strlen(str) + 1, str);
		cout << "Enter model of overcoat ";
		cin.getline(str, 256);
		model = new char[strlen(str) + 1];
		strcpy_s(model, strlen(str) + 1, str);

		cout << "Enter price ";
		cin >> price;
		fflush(stdin);
		Increment();
	}
	~Overcoat()
	{
		if (type)
			delete[]type;
		if (model)
			delete[]model;
		Decrement();
	}
	void Increment()
	{
		count++;
	}
	void Decrement()
	{
		count--;
	}

	//1.	Проверка на равенство типов одежды (операция ==)
	bool operator==(const Overcoat& Obj)
	{
		//cout << "bool ==\n";
		return type == Obj.type;
	}

	//2.	Операцию присваивания одного объекта в другой(операция =)
	Overcoat& operator=(const Overcoat& Obj)
	{
		cout << "operator =\n";
		if (this == &Obj)
			return *this;
		if (type)
			delete[]type;
		if (model)
			delete[]model;
		type = new char[strlen(Obj.type) + 1];
		strcpy_s(type, strlen(Obj.type) + 1, Obj.type);
		model = new char[strlen(Obj.model) + 1];
		strcpy_s(model, strlen(Obj.model) + 1, Obj.model);
		price = Obj.price;

		return *this;
	}
	//
	Overcoat& operator=(Overcoat&& Obj)
	{
		cout << "Move Operator = ...\n";

		if (this == &Obj)
			return *this;
		if (type)
			delete[]type;
		if (model)
			delete[]model;

		type = Obj.type;
		Obj.type = NULL;
		model = Obj.model;
		Obj.model = NULL;

		price = Obj.price;
		Obj.price = 0;
		return *this;
	}

	//3.	Сравнение по цене двух пальто одного типа(операция>)
	bool operator>(const Overcoat& Obj)
	{
		cout << "operator >\n";

		if (strcmp(type, Obj.type))
			return false;
		if (price > Obj.price)
			return false;
		return true;
	}

	//
	void ShowOvercoat()
	{
		cout << "Type of overcoat: " << type << "\tModel: " << model << "\tPrice: " << price;
		cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	}

};
int Overcoat::count = 0;

int _tmain(int argc, _TCHAR* argv[])
{
	Overcoat arr1;
	//arr1.SetOvercoat();
	Overcoat arr2("winter", "44-46", 56.18);
	Overcoat arr3;
	arr3 = Overcoat("winter", "44-46", 56.18);

	cout << "Enter COUNT of overcoat: ";
	int size;
	cin >> size;
	fflush(stdin);
	Overcoat* arr4;
	arr4 = new Overcoat[size];
	for (int i = 0; i < size; i++)
		arr4[i].SetOvercoat();
	Overcoat arr5("winter", "42-42", 50.08);

	arr1.ShowOvercoat();
	arr2.ShowOvercoat();
	arr3.ShowOvercoat();
	for (int i = 0; i < size; i++)
		arr4[i].ShowOvercoat();
	arr5.ShowOvercoat();


	(arr5 == arr2) ? cout << "Similar types of overcoat\n" : cout << "Different types of overcoat\n";
	(arr2 == arr3) ? cout << "Similar types of overcoat\n" : cout << "Different types of overcoat\n";

	(arr1 > arr2) ? cout << "The first price is higher\n" : cout << "The first price is lower or similar\n";





	system("pause");
	return 0;
}

