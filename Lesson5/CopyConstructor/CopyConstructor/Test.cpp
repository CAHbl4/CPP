#include "stdafx.h"
#include "Test.h"


Test::Test(int value)
{
	cout << "Constuctor is working\n";
	data = new int;
	*data = value;
}

void Test::SetData(int value)
{
	*data = value;
}

Test::Test(const Test& obj)
{
	cout << "Copy Constructor is working\n";
	data = new int;
	*data = *obj.data;
}

void Test::ShowData() {
	cout << "Data: " << *data << "\nAdress: " << data << endl;
}

Test::~Test()
{
	cout << "Destructor is working\n";
}

void function1(Test obj)
{
	cout << "Calling function1\n";
	obj.SetData(111);
	obj.ShowData();
}

Test function2()
{
	cout << "Calling function2\n";
	Test tmp;
	tmp.ShowData();
	return tmp;
}