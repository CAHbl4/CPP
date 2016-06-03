#pragma once
class Student {
	char* name;
	char* surname;
	int age;
	static int countStudent;
public:
	Student(char* name = "\0", char* surname = "\0", int age = 0);

	Student(const Student& other);

	Student& operator=(const Student& other);

	bool operator==(const Student& other) const;

	friend istream& operator>>(istream& in, Student& obj);
	friend ostream& operator<<(ostream& out, const Student& obj);

	~Student();
};
