// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Fraction.h"


int main()
{
	Fraction f1(2, 3);
	Fraction f2(1, 6);
	f1.Add(f2);
	f1.Show();
	f1.Div(3, 7);
	f1.Show();

	system("pause");
    return 0;
}

