// stdafx.cpp: �������� ����, ���������� ������ ����������� ���������� ������
// Friend_Class.pch ����� ������������������� ����������
// stdafx.obj ����� ��������� �������������� ����������������� �������� � ����

#include "stdafx.h"

// TODO: ���������� ������ �� ����� ����������� �������������� ��������� � ����� STDAFX.H
// , � �� � ������ �����

istream& operator>>(istream& in, Point& obj)
{
	cout << "Enter coordinates of point: ";
	cin >> obj.x >> obj.y;
	return in;
}


ostream& operator<<(ostream& out, const Point& obj)
{
	out << "Point(" << obj.x << ", " << obj.y << ")\n";
	return out;
}