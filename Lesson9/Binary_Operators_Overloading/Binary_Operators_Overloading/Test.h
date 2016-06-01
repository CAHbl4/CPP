#pragma once

class Test
{
	int *data;
public:
	Test(int value = 0);
	Test(const Test& other);
	Test& operator=(const Test& other);

	Test operator+(const Test& rval) const;


	int GetData() const;
	void Show() const;

	~Test();
};
