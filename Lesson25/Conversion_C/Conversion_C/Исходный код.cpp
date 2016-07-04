#include <iostream>
using namespace std;

int main()
{
	//Преобразования С
	//char->int->long->double
	//с потерей данных
	//char<-int<-long<-double
	//использование явных преобразований
	char a = 'A';
	cout << "char=" << a << ", int=" << (int)a;
	cout << ", double=" << (double)a<<endl;
	double x = 1234.5678E20;
	cout << "double x=" << x << ", int x=" << (int)x;
	cout << ", char x=" << char(x) << endl;

	//использование неявных преобразований
	//неявное преобразование к double
	cout << "5+7.8=" << (5 + 7.8) << endl;
	int b = 7;
	cout << "b/(1+1.5)=" << b /(1+1.5) << endl;
	//неявное преобразование к int
	b = 2 + sin(2.5);
	cout << "b=" << b<<endl;

	system("pause");
	return 0;
}
