// Auto_ptr.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include<string>
//��� ������ �� smart pointers
#include <memory>

using namespace std;


class Report
{
private:
	string str;
public:
	Report(string s) : str(s)
	{
		cout << "Object created!\n";
	}
	~Report() { cout << "Object deleted!\n"; }
	void comment()
	{
		cout<<str<<endl;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	{
		auto_ptr<Report> ps(new Report("using auto_ptr"));
		ps->comment(); // ������������� �������� -> ��� ������ �������-����� 
	
		Report* ptr = new Report("Using regular ptr");
		ptr->comment();
		delete ptr;
	}
	cout << "-------------------------------\n";
	{
		shared_ptr<Report> ps(new Report("using shared_ptr"));
		ps->comment();
	}
	{
		unique_ptr<Report> ps(new Report("using unique_ptr"));
		ps->comment();
	}

	//����� ��������
	auto_ptr<string> films[5] =
	{
		auto_ptr<string>(new string("������� ����")),
		auto_ptr<string>(new string("����������")),
		auto_ptr<string>(new string("� ��� ���� ���� �������")),
		auto_ptr<string>(new string("�������")),
		auto_ptr<string>(new string("�����������"))
	};

	//auto_ptr<string> pwin;
	//pwin = films[2];   // films[2] ������ ����� �������������

	cout << "�������� �� ������ �����\n";
	for (int i = 0; i < 5; i++)
		cout << *films[i] << endl;
	auto_ptr<string> pwin;
	pwin = films[2];   // films[2] ������ ����� �������������
	cout << "The winner is " << *pwin << "!\n";
	
	system("pause");
	return 0;
}

