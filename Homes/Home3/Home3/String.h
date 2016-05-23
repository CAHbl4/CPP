#pragma once
class String
{
	char* string;
	int length;
	static int created;
public:
	String(int length = 80);
	String(const char* string);

	void InputString();
	char* GetString();
	int GetLength();

	void ShowString();
	
	static int GetCreated();

	~String();
};

