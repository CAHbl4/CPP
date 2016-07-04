// Dynamic_Cast_Prata.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;


//базовый класс
class Grand
{
private:
	int hold;
public:
	Grand(int h = 0) : hold(h) {}
	virtual void Speak() const { cout << "I am a grand class!\n"; }
	//виртульный метод получения значения закрытого поля hold (getter)
	virtual int GetValue() const { return hold; }
};

//первый класс наследник
class Superb : public Grand
{
public:
	Superb(int h = 0) : Grand(h) {}
	//переопределяется виртуальный метод Speak
	void Speak() const { cout << "I am a superb class!!\n"; }
	//добавляется новый виртуальный метод Say
	virtual void Say() const
	{
		cout << "I hold the superb value of " << GetValue() << "!\n";
	}
};

//самый последний наследник (великолепный)
class Magnificent : public Superb
{
	//дополнительное поле 
private:
	char ch;
public:
	Magnificent(int h = 0, char c = 'A') : Superb(h), ch(c) {}
	//переопределяется виртуальный метод Speak
	void Speak() const { cout << "I am a magnificent class!!!\n"; }
	//переопределяется виртуальный метод Say
	void Say() const
	{
		cout << "I hold the character " << ch <<
		" and the integer " << GetValue() << "!\n";
	}
};

//функция создания объекта и возвращение указателя на созданный объект
Grand* GetOne();

int _tmain(int argc, _TCHAR* argv[])
{
		//запускаем генератор случайных чисел
		std::srand(std::time(0));
		//создаем указатели на базовый класс и первого наследника
		Grand * pg;
		//указатель на первого наследника необходим для вызова метода Say
		Superb * ps;
		for (int i = 0; i < 5; i++)
		{
			//создаем объект и получаем указатель, работаем через указатель базового класса
			pg = GetOne();
			//вызываем метод Speak
			pg->Speak();
			//пытаемся привести указатель базового класса к указателю на первого наследника
			//для вызова метода Say
			//метод Say для объекта базового класса не вызывается (его нет в базовом классе)
			if (ps = dynamic_cast<Superb *>(pg))
				ps->Say();
		}
		std::cin.get();
		return 0;
	}

//функция создания объекта и возвращение указателя на созданный объект
Grand * GetOne()    // generate one of three kinds of objects randomly
{
	Grand * p=NULL;
	//генерируем случайное число (0-2)
	switch (std::rand() % 3)
	{
		//если 0 создаем объект класса Grand
	case 0: p = new Grand(std::rand() % 100);
		break;
		//если 1 создаем объект класса Superb
	case 1: p = new Superb(std::rand() % 100);
		break;
		//если 2 создаем объект класса Magnificent
	case 2: p = new Magnificent(std::rand() % 100,
		'A' + std::rand() % 26);
		break;
	}
	//возвращаем указатель на созданный объект
	return p;
}



