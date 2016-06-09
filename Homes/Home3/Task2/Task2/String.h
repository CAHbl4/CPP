#pragma once

class String {
	int length;
	char* str;
public:
	String(const char* str = "\0");
	String(const String& other);
	String(String&& other);
	String& operator=(const String& other);
	String& operator=(String&& other);

	String operator+(const String& obj) const;

	friend bool operator==(const String& lhs, const String& rhs) {
		return !strcmp(lhs.str, rhs.str);
	}

	friend bool operator!=(const String& lhs, const String& rhs) {
		return !(lhs == rhs);
	}

	~String();

	friend std::ostream& operator<<(std::ostream& os, const String& obj) {
		return os << obj.str;
	}
};
