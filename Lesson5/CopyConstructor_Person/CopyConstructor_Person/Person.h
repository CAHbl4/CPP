#pragma once
class Person
{
	int age;
	char* name;
public:
	Person();

	Person(const char* name, int age) : age(age)
	{
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
	}

	Person& operator=(const Person& obj);

	Person(const Person& obj);

	void SetData();

	void Show();

	~Person();
};

