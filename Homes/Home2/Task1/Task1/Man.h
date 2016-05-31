#pragma once
class Man {
	char* name;
	int length;
public:
	Man(const char* name = "\0");
	Man(const Man& other);

	char* GetName() const;
	void SetName(const char* name);

	Man& operator=(const Man& other);

	~Man();
};
