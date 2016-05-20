// Static_Members.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Car.h"


int main()
{
	cout << "Count: " << Car::GetCount() << endl;

	Car::SetCount(3);

	Car car1;
	car1.Show();
	car1.SetCount(10);
	Car car2;

	cout << "Count: " << Car::GetCount() << endl;
    return 0;
}

