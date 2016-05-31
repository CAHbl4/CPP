// Array_Operators_Overloading.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Array.h"


int _tmain(int argc, _TCHAR* argv[])
{
	Array arr1(3);
	arr1.Show();
	Array arr2(5);
	arr2.Show();

	Array arr3;
	arr3 = arr1;
	arr3.Show();
	cout << "-----------------\n";
	++arr3;
	arr3.Show();
	arr3++;
	arr3.Show();
	cout << "-----------------\n";
	Array arr4 = arr3;
	arr4 = arr3--;
	arr4.Show();
	--arr4;
	arr4.Show();
	--arr4;
	arr4.Show();
	--arr4;
	arr4.Show();

	cout << "-----------------\n";
	//arr1.Set(0, 777);
	arr1[0] = 777;
	arr1.Show();

	cout << "arr1[1]=" << arr1[1] << endl;

	system("pause");
	return 0;
}

