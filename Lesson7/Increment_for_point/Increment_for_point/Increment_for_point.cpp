// Increment_for_point.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	Point(int x = 0, int y = 0) : x(x), y(y){}
	void Show()
	{
		cout << "Point(" << x << "," << y << ")\n";
	}

	Point& operator++(){
		cout << "Prefix\n";
		++x;
		++y;
		return *this;
	}

	Point operator++(int){
		cout << "Postfix\n";
		Point tmp = Point(x, y);
		++x;
		++y;
		return tmp;
	}

	Point& operator--(){
		cout << "Prefix\n";
		--x;
		--y;
		return *this;
	}

	Point operator--(int){
		cout << "Postfix\n";
		Point tmp = Point(x, y);
		--x;
		--y;
		return tmp;
	}

};

int _tmain(int argc, _TCHAR* argv[])
{
	Point p1(3, 3);
	p1.Show(); 
	p1++;
	p1.Show();
	Point p2 = ++p1;
	p2.Show();

	--p2;
	p2.Show();

	system("pause");
	return 0;
}
