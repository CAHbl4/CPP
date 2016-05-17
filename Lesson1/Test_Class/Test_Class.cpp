// Test_Class.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

class Counter2
{
	int current;

public:

	explicit Counter2()
	{
		current = 0;
	}

	int get_current() const
	{
		return current;
	}

	void set_current(int value)
	{
		current = value;
	}

	void Increment()
	{
		++current;
	}

	void Decrement()
	{
		--current;
	}

	void Show();
};

void Counter2::Show()
{
	std::cout << "Current value - " << current << std::endl;
}


int _tmain(int argc, _TCHAR* argv[])
{

	Counter2 c1;
	c1.Show();
	c1.set_current(10);
	c1.Show();
	c1.Increment();
	c1.Show();
	c1.Decrement();
	c1.Show();

	//std::wcout << "Count of arguments - " << argc << std::endl;
	//std::wcout << "Params:" << std::endl;
	//for (auto i = 0; i < argc; ++i)
	//	std::wcout << argv[i] << std::endl;

    return 0;
}