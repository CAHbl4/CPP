// Lyambda.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

int rnd()
{
	return rand() % 100;
}

bool f5(int x){ return x % 5==0; }
bool f3(int x){ return x % 3 == 0; }

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	vector<int> v1(15);
	generate(v1.begin(), v1.end(), rnd);
	//�����
	for (auto a : v1)
	{
		cout << a << " ";
	}
	cout << endl;

	//������� ���������� �����, ������� 5
	int kol5 = count_if(v1.begin(), v1.end(),f5);
	cout << "���������� �����, ������� 5 = " << kol5 << endl;

	//������� ���������� �����, ������� 3
	int kol3 = count_if(v1.begin(), v1.end(), f3);
	cout << "���������� �����, ������� 3 = " << kol3 << endl;

	//������������� ���������
	class Fmod
	{
	private:
		int dv;
	public:
		Fmod(int d = 1) : dv(d) {}
		bool operator()(int x) { return x % dv == 0; }
	};
	
	cout << "������������� ��������\n";
	//������� ���������� �����, ������� 5
	int kr = 5;
	int kol51 = count_if(v1.begin(), v1.end(), Fmod(kr));
	cout << "���������� �����, ������� " <<kr<<" = " << kol51 << endl;

	//������� ���������� �����, ������� 3
	int kol31 = count_if(v1.begin(), v1.end(), Fmod(3));
	cout << "���������� �����, ������� 3 = " << kol31 << endl;

	//������������� ������-�������
	//������������� ���������� ������-�������
	int kol52 = count_if(v1.begin(), v1.end(), [](int x){return x % 5 == 0; });
	//������������� ������������ ������-�������
	int kr3=3;
	auto mod3 = [&kr3](int x){return x % kr3 == 0; };
	int kol32 = count_if(v1.begin(), v1.end(), mod3);
	cout << "������������� ������\n";
	cout << "���������� �����, ������� " << kr << " = " << kol51 << endl;
	cout << "���������� �����, ������� 3 = " << kol31 << endl;



	system("pause");
	return 0;
}

