#pragma once
class String
{
	int size;
	char* str;
public:
	String(char* str = "\0") : size(strlen(str))
	{
		this->str = new char[size + 1];
		strcpy_s(this->str, size + 1, str);
	}


	String(const String& other)
	{
		size = other.size;
		str = new char[size + 1];
		strcpy_s(str, size + 1, other.str);
	}


	String& operator=(const String& other)
	{
		if (this == &other)
			return *this;
		if (str)
			delete[] str;
		size = other.size;
		str = new char[size + 1];
		strcpy_s(str, size + 1, other.str);
		return *this;
	}

	void Show() const
	{
		cout << str << endl;
	}

	String operator+(const String& other){
		String tmp;
		tmp.size = size + other.size;
		if (tmp.str)
			delete[] tmp.str;
		tmp.str = new char[tmp.size + 1];
		strcpy_s(tmp.str, tmp.size + 1, str);
		strcat_s(tmp.str, tmp.size + 1, other.str);
		return tmp;
	}


	~String()
	{
		if (str)
			delete[] str;
	}
};
