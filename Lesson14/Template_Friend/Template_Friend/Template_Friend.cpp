// Template_Friend.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

template<class T, class T2>
class Point
{
	T x, y;
	T2 name;
public:
	Point(T a, T b, T2 c) :x(a), y(b), name(c) {}

	friend istream& operator>><T, T2>(istream& in, Point<T, T2>& Obj);
	friend ostream& operator<<<T, T2>(ostream& out, const Point<T, T2>& Obj);
};

template<class T>
class Point<T, char*>
{
	T x, y;
	char* name;
public:
	Point(T a, T b, char* c) :x(a), y(b) {
		name = new char[strlen(c) + 1];
		strcpy_s(name, strlen(c) + 1, c);
	}

	friend istream& operator>><T, char*>(istream& in, Point<T, char*>& Obj);
	friend ostream& operator<<<T, char*>(ostream& out, const Point<T, char*>& Obj);
	~Point() {
		if (name)
			delete[] name;
	}
};


template<class T, class T2>
istream& operator>>(istream& in, Point<T, T2>& Obj)
{
	cout << "Enter point:";
	in >> Obj.x >> Obj.y;
	return in;
}

template<class T, class T2>
ostream& operator<<(ostream& out, const Point<T, T2>& Obj)
{
	out << Obj.name << "(" << Obj.x << "," << Obj.y << ")\n";
	return out;
}


int main()
{
	Point<int, char> p1(3, 5, 'A');
	cout << p1;
	Point<double, char*> p2(1.2, 3.4, "Point");
	cout << p2;
	/*cin >> p2;
	cout << p2;*/
	cout << "-----------------------------------------------\n";


	system("pause");
	return 0;
}

