// Auto_ptr.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include<string>
//для работы со smart pointers
#include <memory>

using namespace std;


class Report
{
private:
	string str;
public:
	Report(string s) : str(s)
	{
		cout << "Object created!\n";
	}
	~Report() { cout << "Object deleted!\n"; }
	void comment()
	{
		cout<<str<<endl;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	{
		auto_ptr<Report> ps(new Report("using auto_ptr"));
		ps->comment(); // использование операции -> для вызова функции-члена 
	
		Report* ptr = new Report("Using regular ptr");
		ptr->comment();
		delete ptr;
	}
	cout << "-------------------------------\n";
	{
		shared_ptr<Report> ps(new Report("using shared_ptr"));
		ps->comment();
	}
	{
		unique_ptr<Report> ps(new Report("using unique_ptr"));
		ps->comment();
	}

	//права владения
	auto_ptr<string> films[5] =
	{
		auto_ptr<string>(new string("Зеленая миля")),
		auto_ptr<string>(new string("Терминатор")),
		auto_ptr<string>(new string("В бой идут одни старики")),
		auto_ptr<string>(new string("Офицеры")),
		auto_ptr<string>(new string("Добровольцы"))
	};

	//auto_ptr<string> pwin;
	//pwin = films[2];   // films[2] теряет право собственности

	cout << "Номинант на лучший фильм\n";
	for (int i = 0; i < 5; i++)
		cout << *films[i] << endl;
	auto_ptr<string> pwin;
	pwin = films[2];   // films[2] теряет право собственности
	cout << "The winner is " << *pwin << "!\n";
	
	system("pause");
	return 0;
}

