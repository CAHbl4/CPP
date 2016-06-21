// Inheritance_Template.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

template<class T1,class T2>
class Point
{
protected:
	T1 x;
	T2 y;
public:
	Point(T1 x = 0, T2 y = 0) :x(x), y(y)
	{	}
	void Show()
	{
		cout << "Point(" << x << "," << y << ")\n";
	}
};

template<class T1,class T2,class T3>
class Point3D :public Point<T1,T2>
{
	T3 z;
public:
	Point3D(T1 x = 0, T2 y = 0, T3 z = 0) :Point<T1,T2>(x, y), z(z){}
	void Show()
	{
		cout << "Point3D(" << x << "," << y << "," << z << ")\n";
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	Point<char,int> p1('A', 'B');
	p1.Show();
	Point3D<int,double,char> p2(2, 3.5,'B');
	p2.Show();
	p2.Point::Show();
	system("pause");
	return 0;
}

