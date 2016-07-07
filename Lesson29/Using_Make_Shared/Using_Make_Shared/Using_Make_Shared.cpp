// Using_Make_Shared.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>
#include <string>
#include <memory>

using namespace std;

struct Address
{
	int HouseNumber;
	string StreetName;
	Address(int houseNumber, const string streetName)
		: HouseNumber(houseNumber), StreetName(streetName) {}
};

struct Person
{
	int Age;
	string Name;
	shared_ptr<Address> HomeAddress;
	Person(int age, const string name, shared_ptr<Address> homeAddress)
		: Age(age), Name(name), HomeAddress(homeAddress) {}
};

int _tmain(int argc, _TCHAR* argv[])
{
	auto address = make_shared<Address>(221, "Baker St");
	auto person = make_shared<Person>(40, "Sherlock", address);
	cout << "Name - " << person->Name << endl;
	cout << "Age - " << person->Age << endl;
	cout << "Adress:\n";
	cout << (person->HomeAddress)->StreetName << endl;
	cout << "house - " << (person->HomeAddress)->HouseNumber << endl;
	system("pause");

	return 0;
}

