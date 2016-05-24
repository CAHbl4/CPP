// CopyConstructor_Person.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Person.h"


int _tmain(int argc, _TCHAR* argv[])
{

	system("cls");

	//Person p1;
	//p1.SetData();
	//p1.Show();
	//Person p2("Alex", 25);
	//p2.Show();

	{
		Person p1, p2;
		p2.SetData();
		p1 = p2;
		p1.Show();
		p2.Show();
		cout << "------------------------------------\n";
		//p1.SetData();
		//p1.Show();
		//p2.Show();
		Person p3 = p2;
		p3.Show();
		system("pause");

	}

	system("pause");
	return 0;
}