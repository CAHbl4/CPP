#pragma once
class Car
{
	char model[20];
	static int count;

public:
	Car();
	void Show();
	static int GetCount();
	static void SetCount(int count);
	~Car();
};