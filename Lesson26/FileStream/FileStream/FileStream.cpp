// FileStream.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
//��� ������ � �������
#include <fstream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	//������ ������ � ����
	int a = 2;
	double pi = 3.14;
	char* str = "One!!!";
	

	//�������� ��������� ������
	try
	{
		fstream file("test.txt", ios::out);   //out - ������ � ����
		if (!file)
			throw exception ("Error...");
		file << "a=" << a << ", pi= " << pi << ", str=" << str << endl;
		//����� ������ � ������ ��� ���� �������
		file.close();

		//���������� ������ �� ���������� �����
		fstream filein("test.txt", ios::in);		//in - ������
		if (!file)
			throw exception("Error...");
		char str[256];
		filein >> str;		//��������� �� �������
		cout << str << endl;	

		//������ ���������� �����
		filein.seekp(ios::beg);//������������� ��������� �� ������ �����
		char result[256];
		result[0] = '\0';
		//�������������� ���� ���� �� ����� ��������� ����� �����
		while (!filein.eof())
		{
			filein >> str;
			strcat_s(result, 256, str);
			cout << str << endl;
		}
		filein.close();
		cout << result << endl;
		//������� 2
		cout << "-----------Variant 2-----------------\n";
		fstream f2("test.txt", ios::in);
		if (!f2)
			throw exception("Error...");
		char str2[256];
		while (f2.getline(str2,256))
		{
			//f2.getline(str2, 5);
			cout << str2<<endl;
		}
		f2.close();
		//������� 3
		cout << "-----------Variant 3-----------------\n";
		fstream f3("test.txt", ios::in);
		if (!f3)
			throw exception("Error...");
		//���������� �����������
		char �h;
		while (!f3.eof())
		{
			�h=f3.get();
			cout <<�h;
		}
		f3.close();
		//������� 4
		cout << "-----------Variant 4-----------------\n";
		fstream f4("test1.txt", ios::in);
		if (!f4)
			throw exception("Error...");
		//���������� �� ������
		cout << f4.rdbuf();
		f4.close();
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}

	system("pause");
	return 0;
}

