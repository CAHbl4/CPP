#include "stdafx.h"
#include "Test.h"


Test::Test(int value)
{
	data = new int;
	*data = value;
}


Test::Test(const Test& other)
{
	data = new int;
	*data = *other.data;
}


Test& Test::operator=(const Test& other)
{
	if (this == &other)
		return *this;

	if (data)
		delete data;

	data = new int;
	*data = *other.data;

	return *this;
}


Test Test::operator+(const Test& rval) const
{
	int tmp;
	tmp = *data + *rval.data;
	return Test(tmp);
}


int Test::GetData() const
{
	return *data;
}


void Test::Show() const
{
	cout << "Data: " << *data << endl;
}


Test::~Test()
{
	if (data)
		delete data;
}
