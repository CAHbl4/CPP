// Explicit_Constructor.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Test
{
	int *data;
public:
	explicit Test(int value = 0)
	{
		cout << "Default Constructor\n";
		data = new int;
		*data = value;
	}

	~Test()
	{
		cout << "Destructor\n";
		if (data)
			delete data;
	}

	Test(const Test& other)
	{
		cout << "Copy Constructor\n";
		data = new int;
		*data = *other.data;
	}

	void Show()
	{
		cout << "Data: " << *data << endl;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Test t1(5);
	t1.Show();
	Test t2 = t1;
	t2.Show();

	//Test t3 = 10; //Ќе€вное преобразование запрещено explicit
	//t3.Show();

	Test t4 = Test(25);
	t4.Show();

	system("pause");
	return 0;
}

