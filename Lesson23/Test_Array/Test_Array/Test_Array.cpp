// Test_Array.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include<iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int n;//������ �������
	int *array=NULL;
	bool f1 = true;
	while (f1)
	{
		try
		{
			cout << "Enter size:";
			cin >> n;
			if (n <= 0)
				throw n;
			array = new int[n];
			for (int i = 0; i < n; i++)
				array[i] = rand() % 100;
			f1 = false;
		}
		catch (int n)
		{
			cout << "You enter n=" << n << endl;
			cout << "N must be >0!!!\n";
		}
	}
	//����� �������
	for (int i = 0; i < n; i++)
		cout << array[i] << "\t";
	cout << endl;
	system("pause");
	return 0;
}

