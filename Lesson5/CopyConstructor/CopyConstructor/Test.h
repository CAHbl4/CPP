#pragma once
class Test
{
	int* data;
public:
	Test(int value = 0);

	void SetData(int value);

	Test(const Test& obj);

	void ShowData();
	~Test();
};

void function1(Test obj);

Test function2();
