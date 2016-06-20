// Inheriance.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Point
{
//область видимости полей в методах данного класса и его наследников
protected:
	int x, y; 
public:
	Point(int x = 0, int y = 0) :x(x), y(y){ cout << "Constructor Point!!!\n"; }
	//перегрузка ввода-вывода
	friend istream& operator>>(istream& in, Point& Obj);
	friend ostream& operator<<(ostream& out, const Point& Obj);
	//объявляем другом класс треугольник
	void Show()
	{
		cout << "Point(" << x << "," << y << ")\n";
	}
	~Point()
	{
		cout << "Destructor Point!!!\n";
	}


};
//перегрузка ввода
istream& operator>>(istream& in, Point& Obj)
{
	cout << "Enter coordinates of Point:";
	in >> Obj.x >> Obj.y;
	return in;
}

//перегрузка вывода
ostream& operator<<(ostream& out, const Point& Obj)
{
	out << "Point(" << Obj.x << "," << Obj.y << ")\n";
	return out;
}

//агрегированный класс
class Point3D
{
	//содержит поле, которое явлется указателем на объект класса Point
	Point *ptr;
	//третья координата
	int z;
public:
	Point3D(int x = 0, int y = 0, int z = 0) :z(z)
	{
		ptr = new Point(x, y);
	}
	~Point3D()
	{
		
		if (ptr)
		delete ptr;
		cout << "Destructor Point3D!!!\n";
	}
	void Show()
	{
		cout << *ptr;
		cout << z <<endl ;
	}
};


//наследуемый класс от класса Point
//указывается :public Point
class Point3D2 :public Point
{
	int z;
public:
	//конструктор производного класса
	Point3D2(int x = 0, int y = 0, int z = 0) :z(z), 
		//делегируем инициализацию полей x,y конструктору базового класса
		Point(x,y)
	{
		cout << "Constructor Point3D2!!!\n";
	}
	//метод show производного класса
	void Show()
	{
		//обращение к методу show базового класса
		cout << "Method Show base class\n";
		Point::Show();
		cout << "Method Show inheritable class\n";
		cout << "Point(" << x << "," << y << "," << z << ")\n";
	}
	~Point3D2()
	{
		cout << "Destructor Point3D2!!!\n";
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	{
		Point3D p1(1, 2, 3);
	p1.Show();
	Point3D2 p2(4, 8, 111);
	p2.Show();
	p2.Point::Show();

	}system("pause");
	return 0;
}

