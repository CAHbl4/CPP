#pragma once
class Rectangle
{
	float length;
	float width;
public:
	Rectangle(float length = 0, float width = 0) :
		length(length),
		width(width)
	{
		cout << "Rectangle's Constructor is working.\n";
	}

	void SetWidth(float width)
	{
		this->width = width;
	}

	void SetLength(float length)
	{
		this->length = length;
	}

	void SetAll(float width, float length)
	{
		SetWidth(width);
		SetLength(length);
	}

	float Square()
	{
		return length * width;
	}

	~Rectangle();
};

