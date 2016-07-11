// Using_Vector.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
//��� ������ � ��������
#include<vector>
//��� ������ � �����������
#include<algorithm>

using namespace std;

template<class T>
void show(vector<T> v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << "\t";
	cout << endl;
}

//������� ��� ��������� for_each
template<class T>
void print(T x)
{
	cout << x << "\t";
}



int _tmain(int argc, _TCHAR* argv[])
{
	//��������
	vector<int> v1;//�������� ������� �������
	vector<double> v2(5);//������ �� 5 ��������� ������������� ����
	vector<char> v3 = { 'A', 'B', 'C' };//������ �� 3 ��������
	//������� ������
	int arr[] = { 1, 2, 3, 4, 5, 6 };
	//�������� �� ������������� �������
	vector<int> v4(arr, arr + 5);
	vector<char> v5(3, '!');//������ �� 3 ������� !
	
	//����� �����������
	cout << "---------V1-------------\n";
	show(v1);
	cout << "---------V2-------------\n";
	show(v2);
	cout << "---------V3-------------\n";
	show(v3);
	cout << "---------V4-------------\n";
	show(v4);
	cout << "---------V5-------------\n";
	show(v5);
	
	//����� � �������������� ��������� for_each
	cout << "----------For_Each-----------\n";
	for_each(v4.begin(), v4.end(), print<int>);
	cout << endl;
	for_each(v4.begin(), v4.end(), print<char>);
	cout << endl;

	//����� ����� for (�������� C++11)
	cout << "---------------For-----------------\n";
	
	for (auto a : v4)
	{
		cout << a << "\t";
	}
	cout << endl;

	
	for each(auto a in v4)
	{
		cout << a << "\t";
	}
	cout << endl;
	//������������ ��������
	cout << "--------------Vector V1------------\n";
	//��������� ����������� ����������
	v1.assign(5, 1);
	for (auto a : v1)
	{
		cout << a << "\t";
	}
	cout << endl;
	//���������� � ����� � ������
	v1.push_back(5);
	v1.push_back(7);
	show(v1);
	//��������� ��������
	v1[3] = 33;
	v1.at(0) = 100;
	show(v1);







	system("pause");
	return 0;
}

