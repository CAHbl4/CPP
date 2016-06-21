// Agregation.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

//�������� ������ �����������, ����� ����� ����� ���� � ���
class Triangle;

class Point
{
	int x, y; friend Triangle;
public:
	Point(int x = 0, int y = 0) :x(x), y(y){}
	//���������� �����-������
	friend istream& operator>>(istream& in, Point& Obj);
	friend ostream& operator<<(ostream& out, const Point& Obj);
	//��������� ������ ����� �����������

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

class Triangle
{
	Point  *A, *B, *C;
public:
	Triangle(Point* A, Point* B, Point* C) :A(A), B(B), C(C){}
	void ShowCordinates()
	{
		cout << "Triangle:\n";
		cout << "A:(" << A->x << "," << A->y << ")\n";
		cout << "B:(" << B->x << "," << B->y << ")\n";
		cout << "C:(" << C->x << "," << C->y << ")\n";
	}
	~Triangle()
	{
		A = B = C = NULL;
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	Point p1;
	cin >> p1;
	cout << p1;
	Point p2;
	cin >> p2;
	cout << p2;
	Point p3;
	cin >> p3;
	cout << p3;
	{Triangle tr1(&p1, &p2, &p3);
	tr1.ShowCordinates(); }
	cout << p1;
	cout << p2;
	cout << p3;

	system("pause");
	return 0;
}


