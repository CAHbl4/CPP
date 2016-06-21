// Inheriance.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Point
{
//������� ��������� ����� � ������� ������� ������ � ��� �����������
protected:
	int x, y; 
public:
	Point(int x = 0, int y = 0) :x(x), y(y){ cout << "Constructor Point!!!\n"; }
	//���������� �����-������
	friend istream& operator>>(istream& in, Point& Obj);
	friend ostream& operator<<(ostream& out, const Point& Obj);
	//��������� ������ ����� �����������
	void Show()
	{
		cout << "Point(" << x << "," << y << ")\n";
	}
	~Point()
	{
		cout << "Destructor Point!!!\n";
	}


};
//���������� �����
istream& operator>>(istream& in, Point& Obj)
{
	cout << "Enter coordinates of Point:";
	in >> Obj.x >> Obj.y;
	return in;
}

//���������� ������
ostream& operator<<(ostream& out, const Point& Obj)
{
	out << "Point(" << Obj.x << "," << Obj.y << ")\n";
	return out;
}

//�������������� �����
class Point3D
{
	//�������� ����, ������� ������� ���������� �� ������ ������ Point
	Point *ptr;
	//������ ����������
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


//����������� ����� �� ������ Point
//����������� :public Point
class Point3D2 :public Point
{
	int z;
public:
	//����������� ������������ ������
	Point3D2(int x = 0, int y = 0, int z = 0) :z(z), 
		//���������� ������������� ����� x,y ������������ �������� ������
		Point(x,y)
	{
		cout << "Constructor Point3D2!!!\n";
	}
	//����� show ������������ ������
	void Show()
	{
		//��������� � ������ show �������� ������
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

