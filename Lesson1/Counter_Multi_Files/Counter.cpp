#include "stdafx.h"
#include "Counter.h"

Counter::Counter(int value)
{
	cout << "Constructor is working" << endl;
	current = value;
}

Counter::~Counter()
{
	cout << "Destructor is working" << endl;
}

int Counter::get_current()
{
	return current;
}

void Counter::set_current(int value)
{
	current = value;
}

void Counter::Increment()
{
	++current;
}

void Counter::Decrement()
{
	--current;
}

void Counter::Show()
{
	cout << "Current value - " << current << endl;
}