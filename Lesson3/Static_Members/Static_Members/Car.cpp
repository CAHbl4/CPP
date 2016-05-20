#include "stdafx.h"
#include "Car.h"

int Car::count = 0;


Car::Car()
{
	cout << "Input model: ";
	cin >> model;
	++count;
}


int Car::GetCount()
{
	return count;
}

void Car::SetCount(int count)
{
	Car::count = count;
}

void Car::Show()
{
	cout << "Car model: " << model << endl;
	cout << "Count of cars: " << count << endl;
}


Car::~Car()
{
	--count;
}