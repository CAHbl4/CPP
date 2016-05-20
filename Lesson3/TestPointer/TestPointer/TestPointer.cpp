// TestPointer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

class Test
{
	int data;
	const int c = 10;
public:
	Test(int value = 0) : data(value) {}
	Test(int value1, int value2) : data(value1), c(value2) {}

	void Show()
	{
		cout << "Data: " << data << endl;
		cout << "Const: " << c << endl;
	}

	void SetData(int data)
	{
		this->data = data;
	}
};


int main()
{
	Test t1(1);
	t1.Show();
	Test t2(2, 5);
	t2.Show();
	Test t3;
	t3.Show();

	Test *ptr;
	ptr = &t2;

	cout << "t2 adress: " << ptr << endl;
	ptr->SetData(7);
	ptr->Show();
	t2.Show();

	Test *ptr1;
	ptr1 = new Test(3, 3);
	ptr1->Show();

	delete ptr1;

	system("pause");
    return 0;
}