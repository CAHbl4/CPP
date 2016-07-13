// Map.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<map>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	string city[] = { "Минск", "Гомель", "Витебск", "Могилев", "Гродно", "Брест" };
	int population[] = { 1938280, 516976, 366299, 374655, 361352, 335645 };
	
	map<string, int, less<string>> mapcity;
	for (int i = 0; i < 6; i++)
	{
		mapcity[city[i]] = population[i];
	}
	for (auto a : mapcity)
		cout << a.first << " - " << a.second << endl;

	mapcity["Мозырь"] = 100000;
	mapcity["Минск"] = 50000;
	cout << "--------------------------------------\n";
	for (auto a : mapcity)
		cout << a.first << " - " << a.second << endl;

	multimap<string, string, less<string>> lib;
	lib.insert(pair<string,string>("Пушкин", "Капитанская дочка"));
	lib.insert(pair<string, string>("Пушкин", "Евгений Онегин"));
	lib.insert(pair<string, string>("Есенин", "Анна Снегина"));
	lib.insert(pair<string, string>("Толстой", "Аэлита"));
	auto iter = lib.find("Пушкин");
	iter->second = "Руслан и Людмила";
	cout << "----------------------------------------\n";
	cout << "Библиотека:\n";
	for (auto a : lib)
		cout << a.first << " - " << a.second << endl;

	system("pause");
	return 0;
}

