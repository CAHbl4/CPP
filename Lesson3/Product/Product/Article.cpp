#include "stdafx.h"
#include "Article.h"

Article::Article()
{
	cout << "Input name of product: ";
	char str[50];
	cin >> str;
	name = new char[strlen(str) + 1];
	strcpy_s(name, strlen(str) + 1, str);
	cout << "Input weigth of product: ";
	cin >> weight;
}

void Article::Show()
{
	cout << "Article: " << name << endl;
	material.Show();
	cout << "Weight: " << weight << endl;
	cout << "Cost: " << material.GetPrice() * weight;
}

Article::~Article()
{
	if (name)
		delete[] name;
}
