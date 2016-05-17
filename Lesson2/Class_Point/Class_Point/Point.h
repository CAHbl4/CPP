#pragma once
class Point
{
	int x, y;
	char name;
public:
	Point();
	//Point(int x, int y, char name);

	Point(int x, int y, char name)
		: x(x),
		  y(y),
		  name(name)
	{
	}

	void Show() const;

	~Point();
};

