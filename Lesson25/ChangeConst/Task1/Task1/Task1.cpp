// Task1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class String
{
public:
	const int SIZE;
	char *name;
	int length;

	String(int s = 10, char *str = "No name") :SIZE(s)
	{
		length = strlen(str);
		name = new char[length + 1];
		strcpy_s(name, length + 1, str);
	}
	String(const String& Obj) :SIZE(Obj.SIZE)
	{
		length = Obj.length;
		name = new char[length + 1];
		strcpy_s(name, length + 1, Obj.name);
	}
	void Show()
	{
		cout << "SIZE=" << SIZE;
		cout << "\nlength=" << length;
		cout << "\nname=" << name<<endl;
	}
	String& operator=(const String& Obj)
	{
		if (this == &Obj)
			return *this;
		const int* p = &SIZE;
		int *q = const_cast<int *>(p);
		*q = Obj.SIZE;
		length = Obj.length;
		name = new char[length + 1];
		strcpy_s(name, length + 1, Obj.name);
				
		return *this;
	}
	~String()
	{
		delete[] name;
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	String str1;
	str1.Show();
	String str2(20, "String2");
	str2.Show();
	String str3(str2);
	str3.Show();
	String str4;
	str4 = str3;
	str4.Show();
	String str5(30,"String5");
	str4 = str5;
	str4.Show();
	system("pause");
	return 0;
}

