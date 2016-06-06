#pragma once
class String {
	int length;
	char* str;
public:
	String() : length(0) {
		cout << "Default constructor\n";
		str = new char[length + 1];
		strcpy_s(str, length + 1, "\0");
	}


	String(const char* str) : length(strlen(str)) {
		cout << "Constructor with parameter\n";
		this->str = new char[length + 1];
		strcpy_s(this->str, length + 1, str);
	}


	String(const String& other)
		: length(other.length) {
		cout << "Copy contructor\n";
		str = new char[length + 1];
		strcpy_s(this->str, length + 1, other.str);
	}


	String(String&& other)
		: length(other.length),
		  str(other.str) {
		cout << "Move constructor\n";
		other.str = nullptr;
		other.length = 0;
	}


	String& operator=(const String& other) {
		cout << "Operator '='\n";
		if (this == &other)
			return *this;
		if (str)
			delete[] str;
		length = other.length;
		str = new char[length + 1];
		strcpy_s(this->str, length + 1, other.str);
		return *this;
	}


	String& operator=(String&& other) {
		cout << "Rval Operator '='\n";
		if (this == &other)
			return *this;
		length = other.length;
		str = other.str;
		other.str = nullptr;
		other.length = 0;
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& os, const String& obj) {
		os << obj.str << endl;
		return os;
	}

	String operator+(const String& obj) const {
		cout << "Operator '+'\n";
		String temp;
		temp.length = length + obj.length;
		temp.str = new char[temp.length + 1];
		strcpy_s(temp.str, temp.length + 1, str);
		strcat_s(temp.str, temp.length + 1, obj.str);
		return temp;
	}

	~String() {
		cout << "Destructor!\n";
		if (str)
			delete[]str;

	}
};
