// Map.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<map>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	string city[] = { "�����", "������", "�������", "�������", "������", "�����" };
	int population[] = { 1938280, 516976, 366299, 374655, 361352, 335645 };
	
	map<string, int, less<string>> mapcity;
	for (int i = 0; i < 6; i++)
	{
		mapcity[city[i]] = population[i];
	}
	for (auto a : mapcity)
		cout << a.first << " - " << a.second << endl;

	mapcity["������"] = 100000;
	mapcity["�����"] = 50000;
	cout << "--------------------------------------\n";
	for (auto a : mapcity)
		cout << a.first << " - " << a.second << endl;

	multimap<string, string, less<string>> lib;
	lib.insert(pair<string,string>("������", "����������� �����"));
	lib.insert(pair<string, string>("������", "������� ������"));
	lib.insert(pair<string, string>("������", "���� �������"));
	lib.insert(pair<string, string>("�������", "������"));
	auto iter = lib.find("������");
	iter->second = "������ � �������";
	cout << "----------------------------------------\n";
	cout << "����������:\n";
	for (auto a : lib)
		cout << a.first << " - " << a.second << endl;

	system("pause");
	return 0;
}

