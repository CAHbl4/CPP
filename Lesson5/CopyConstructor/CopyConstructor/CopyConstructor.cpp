// CopyConstructor.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Test.h"

int _tmain(int argc, _TCHAR* argv[])
{
	{
		Test obj1(10);
		obj1.ShowData();

		cout << "Adress of object: " << &obj1 << endl;

		Test obj2(obj1);
		obj2.ShowData();
		cout << "Adress of object: " << &obj2 << endl;

		Test obj3 = obj1;
		obj3.SetData(777);
		obj3.ShowData();
		cout << "Adress of object: " << &obj3 << endl;

		cout << "====================================\n";
		function1(obj1);
		obj1.ShowData();
	}
	{
		cout << "====================================\n";
		Test obj4 = function2();
		obj4.ShowData();

	}
	system("pause");
	return 0;
}

