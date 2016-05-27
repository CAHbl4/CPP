#pragma once

class String
{
	int size;
	char* str;
public:

	String(char* str = "\0");
	String(const String& other);

	void Show() { cout << str << endl; }

};
