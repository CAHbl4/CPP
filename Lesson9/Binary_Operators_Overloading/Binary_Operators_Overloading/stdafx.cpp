// stdafx.cpp: �������� ����, ���������� ������ ����������� ���������� ������
// Binary_Operators_Overloading.pch ����� ������������������� ����������
// stdafx.obj ����� ��������� �������������� ����������������� �������� � ����

#include "stdafx.h"

// TODO: ���������� ������ �� ����� ����������� �������������� ��������� � ����� STDAFX.H
// , � �� � ������ �����


Test operator+(int lval, const Test& rval){
	int tmp;
	tmp = lval + rval.GetData();
	return Test(tmp);
}