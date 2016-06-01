// Function_Call_Overloading.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Matrix.h"


int _tmain(int argc, _TCHAR* argv[])
{
	Matrix m1(2, 3);
	m1.Show();

	cout << "M[1,2] = " << m1(1, 2) << endl;

	m1(1, 1) = 111;
	m1.Show();

	Matrix m2(m1);
	m2.Show();

	Matrix m3;
	m3 = m2;
	m3.Show();

	system("pause");
	return 0;
}