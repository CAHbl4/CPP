#include <iostream>
using namespace std;

int main()
{
	//�������������� �
	//char->int->long->double
	//� ������� ������
	//char<-int<-long<-double
	//������������� ����� ��������������
	char a = 'A';
	cout << "char=" << a << ", int=" << (int)a;
	cout << ", double=" << (double)a<<endl;
	double x = 1234.5678E20;
	cout << "double x=" << x << ", int x=" << (int)x;
	cout << ", char x=" << char(x) << endl;

	//������������� ������� ��������������
	//������� �������������� � double
	cout << "5+7.8=" << (5 + 7.8) << endl;
	int b = 7;
	cout << "b/(1+1.5)=" << b /(1+1.5) << endl;
	//������� �������������� � int
	b = 2 + sin(2.5);
	cout << "b=" << b<<endl;

	system("pause");
	return 0;
}
