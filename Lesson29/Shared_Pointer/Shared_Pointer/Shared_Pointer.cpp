// Shared_Pointer.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <memory>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{

	setlocale(LC_ALL, "rus");
	shared_ptr<string> films[5] =
	{
		shared_ptr<string>(new string("Зеленая миля")),
		shared_ptr<string>(new string("Терминатор")),
		shared_ptr<string>(new string("В бой идут одни старики")),
		shared_ptr<string>(new string("Офицеры")),
		shared_ptr<string>(new string("Добровольцы"))
	};
	shared_ptr<string> pwin;
	pwin = films[2];   // films[2] и pwin указывают на один и тот же объект

	cout << "Номинант на лучший фильм\n";
	for (int i = 0; i < 5; i++)
		cout << *films[i] << endl;
	cout << "The winner is " << *pwin << "!\n";
	
	system("pause");
	return 0;
}

