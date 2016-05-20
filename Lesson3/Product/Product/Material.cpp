#include "stdafx.h"
#include "Material.h"


Material::Material()
{
	cout << "Input name of material: ";
	char str[50];
	cin >> str;
	name = new char[strlen(str) + 1];
	strcpy_s(name, strlen(str) + 1, str);
	cout << "Input price: ";
	cin >> price;
}

float Material::GetPrice()
{
	return price;
}

void Material::Show()
{
	cout << "Material: " << name << endl;
	cout << "Price: " << price << endl;
}

Material::~Material()
{
	if (name)
		delete[] name;
}