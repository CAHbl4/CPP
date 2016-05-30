// Operators_Overloading.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Counter
{
	int min, max, current;
public:
	Counter(int min = 0, int max = 10) : min(min), max(max), current(min)
	{
		cout << "Default constructor, addr: " << this << endl;
	}

	void Set(int value)
	{
		if (value > max)
			current = min + value % max;
		else if (value < min)
			current = min;
		else
			current = value;
	}

	Counter& operator++(){
		cout << "Prefix form\n";
		current++;
		if (current > max)
			current = min;
		return *this;
	}

	Counter operator++(int){
		cout << "Postfix form\n";
		Counter tmp = *this;
		current++;
		if (current > max)
			current = min;
		cout << "Tmp addr "<< &tmp << endl;
		return tmp;
	}

	void Increment()
	{
		current++;
		if (current > max)
			current = min;
	}

	void Decrement()
	{
		current--;
		if (current < min)
			current = max;
	}

	Counter(const Counter& other)
	{
		cout << "Copy constructor, addr: " << this << endl;
		min = other.min;
		max = other.max;
		current = other.current;
	}

	void Show()
	{
		cout << "Counter's range - " << min << ":" << max << endl;
		cout << "Current value: " << current << ", addr: " << this << endl;
	}

	~Counter()
	{
		cout << "Destructor, addr: " << this << endl;
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	{
		Counter c1;
		c1.Show();
		c1.Set(25);
		c1.Show();

		Counter c2(1, 5);
		c2.Show();
		c2.Set(4);
		c2.Show();

		c2++;
		c2.Show();
		++c2;
		c2.Show();

		Counter c3 = c2++; 
		c2.Show();
		c3.Show();
	}
	system("pause");
	return 0;
}

