// Iterators.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include<iterator>
#include<algorithm>
#include <vector>
#include <fstream>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	
	vector<int> v1 = { 1, 2, 3, 4, 5 };
	
	for (int i = 0; i < v1.size(); i++)
		cout << v1[i] << "\t";
	cout << endl;
	//����� ��������� � ������������� ���������
	//vector<int>::iterator iter;
	auto iter = v1.begin();
	for (; iter != v1.end(); iter++)
		cout << *iter << "\t";
	cout << endl;

	//����� �������� � �������
	//������������ �������� �� �������, ���� ������� � �������� �� ��������� ����� ���������� � ��������� ������
	iter = find(v1.begin(), v1.end(), 3);
	if (iter == v1.end())
		cout << "Element is not exist\n";
	else
		cout << "Element exist! Index: "<<iter-v1.begin()<<endl;

	//������������ ���������� � ���������� copy
	vector<int> v2(v1.size());
	//����������� ����� �������
	copy(v1.begin(), v1.end(), v2.begin());
	for (int i = 0; i < v2.size(); i++)
		cout << v2[i] << "\t";
	cout << endl;
	//����������� ����� �������
	vector<int> v3(5);
	copy(v1.begin()+1, v1.end()-1, v3.begin());
	for (auto a : v3)
	{
		cout << a << "\t";
	}
	cout << endl;

	cout << "Revers iterator:\n";
	//�������� ��������
	vector<int>::reverse_iterator riter;
	for (riter=v1.rbegin(); riter != v1.rend(); riter++)
		cout << *riter << "\t";
	cout << endl;
	
	cout << "Stream irterator:\n";
	//��������� ���������
	ostream_iterator<int> outiter(cout, "\t");//�������� ���������� ������
	copy(v1.begin(), v1.end(), outiter);
	cout << endl;

	ofstream fout("test.txt");
	ostream_iterator<int> foutiter(fout, "\t");//�������� ���������� ������
	copy(v1.begin(), v1.end(), foutiter);
	fout.close();

	ofstream fout1("test1.dat",ios::binary);
	ostream_iterator<int> foutiter1(fout1, "\t");//�������� ���������� ������
	copy(v1.begin(), v1.end(), foutiter1);
	fout1.close();

	//��������� ���������� �����
	vector<int> v4;
	istream_iterator<int> ciniter(cin);//�������� ���������� �����
	istream_iterator<int> cinend;//�������� �� ����� ������
	copy(ciniter, cinend, back_inserter(v4));
	cout << "V4:\n";
	copy(v4.begin(), v4.end(), outiter);
	cout << endl;

	//������ �� �����
	ifstream fin("test.txt");
	istream_iterator<int> fiter(fin);
	vector<int> v5;
	copy(fiter, cinend, back_inserter(v5));
	cout << "V5:\n";
	copy(v5.begin(), v5.end(), outiter);
	cout << endl;
	fin.close();
	cout << "------------------------------\n";
	ifstream fin1("test1.dat",ios::binary);
	istream_iterator<int> fiter1(fin1);
	vector<int> v6;
	copy(fiter1, cinend, back_inserter(v6));
	cout << "V6:\n";
	copy(v6.begin(), v6.end(), outiter);
	cout << endl;
	fin1.close();
	


	

	



	system("pause");
	return 0;
}

