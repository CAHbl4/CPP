#pragma once
class Counter
{
	int current;
public:
	Counter(int value = 0);
	~Counter();
	int get_current();
	void set_current(int value);
	void Increment();
	void Decrement();
	void Show();
};